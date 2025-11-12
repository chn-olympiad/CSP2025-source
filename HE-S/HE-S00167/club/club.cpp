#include<bits/stdc++.h>
using namespace std;
struct node{
    int num,xy;
    bool f=1;
};
bool cmp(node n1,node n2){
    if(n1.num>n2.num){
        return n1.num>n2.num;
    }else{
        return n1.num<n2.num;
    }
}
node a[100001],b[100001],c[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t,sum;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        sum=0;
        for(int j=1;j<=n;j++){
            cin>>a[j].num>>b[j].num>>c[j].num;
            a[j].xy=j,b[j].xy=j,c[j].xy=j;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        int a1=n/2,b1=n/2,c1=n/2;
        for(int j=1;j<=n;j++){
            if(a1>0&&a[j].f==1&&a[j].num>b[j].num&&a[j].num>c[j].num){
                sum+=a[j].num;
                a1--;
                a[j].f=0;
            }else if(b1>0&&b[j].f==1&&b[j].num>a[j].num&&b[j].num>c[j].num){
                sum+=b[j].num;
                b1--;
                b[j].f=0;
            }else if(c1>0&&c[j].f==1&&c[j].num>a[j].num&&c[j].num>b[j].num){
                sum+=c[j].num;
                c1--;
                c[j].f=0;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
