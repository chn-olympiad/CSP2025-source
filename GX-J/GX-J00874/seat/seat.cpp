#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a=n*m,b;
    int s[a];
    for(int i=1;i<=a;i++){
        cin>>s[i];
    }
    int d=s[1];
    if(n==1&&m==1){
        cout<<1<<" "<<1;
        return 0;
    }
    for(int i=1;i<=a;i++){
        for(int j=i;j<=a;j++){
            if(s[i]<s[j]){
                b=s[i];
                s[i]=s[j];
                s[j]=b;
            }
        }
    }
    int c=0;
    for(int i=1;i<=a;i++){
        if(s[i]==d){
            c=i;
        }
    }
    if((c%m)%2==0&&(c/m)%2==0) cout<<c/m<<" "<<1;
    else if((c%m)%2==0&&(c/m)%2==1) cout<<c/m<<" "<<m;
    else if((c/m)%2==0) cout<<(c/m)+1<<" "<<c%m;
    else cout<<(c/m)+1<<" "<<m-(c%m)+1;
    return 0;
}
