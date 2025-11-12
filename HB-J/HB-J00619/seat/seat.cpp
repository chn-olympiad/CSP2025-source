#include<bits/stdc++.h>
using namespace std;

int c[105]={},top=0;
int s[15][15]={};

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        top++;
        cin>>c[i];
    }
    r=c[1];
    sort(c+1,c+n*m+1);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                s[j][i]=c[top];
                top--;
                if(s[j][i]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                s[j][i]=c[top];
                top--;
                if(s[j][i]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
