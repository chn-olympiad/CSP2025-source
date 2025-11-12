#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans,len1,len2,num;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]<a[1]) ans++;
    }
    int pm=n*m-ans;
    if(pm%n==0){
        len1=pm/n;
        num=n;
    }
    if(pm%n!=0){
        len1=pm/n+1;
        num=pm%n;
    }
    if(len1%2==1){
        len2=num;
    }
    if(len1%2==0){
        len2=n-(num-1);
    }
    cout<<len1<<" "<<len2;
    return 0;
}
