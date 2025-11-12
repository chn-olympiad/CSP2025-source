#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,sum,jiji,diao;
int a[10*10+1];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    cin>>n>>m;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    sum=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sum){
            cnt=i;
            break;
        }
    }
    if(cnt>n){
        if(cnt%n==0){
            jiji=cnt/n;
        }else{
            jiji=cnt/n+1;
        }
        if(jiji%2==0){
            diao=n-cnt%n+1;
        }else{
            diao=cnt%n;
        }
    }else{
        jiji=1;
        diao=cnt;
    }
    cout<<jiji<<' '<<diao;
    return 0;
}
