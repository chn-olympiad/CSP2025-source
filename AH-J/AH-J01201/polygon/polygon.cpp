#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[10005],cnt,maxn,sum,s;
bool v[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(n==3){
        int t=max(max(a[1],a[2]),a[3]);
        if((sum-t)>t){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        for(int i=1;i<=n;i++){
            s*=i;
            cout<<s/6;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
