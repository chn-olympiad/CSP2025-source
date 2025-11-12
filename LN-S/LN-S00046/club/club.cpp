#include <bits/stdc++.h>
using namespace std;

int T;
int n;
bool flag;
int ans;
struct pe{
    int c1;
    int c2;
    int c3;
};
pe a[100010];
bool cmp(pe o,pe b){
    return o.c2>b.c2;
}
void maxans(int le,int sum,int num1,int num2,int num3){
    if(le>n){
        ans=max(ans,sum);
        return ;
    }
    if(num1<n/2)maxans(le+1,sum+a[le].c1,num1+1,num2,num3);
    if(num2<n/2)maxans(le+1,sum+a[le].c2,num1,num2+1,num3);
    if(num1<n/3)maxans(le+1,sum+a[le].c3,num1,num2,num3+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        flag=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            if(a[i].c1!=0&&a[i].c3!=0)flag=1;
        }
        if(flag==0){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].c2;
            }
            cout<<ans;
        }else{
            maxans(1,0,0,0,0);
            cout<<ans;
        }

    }
    return 0;
}
