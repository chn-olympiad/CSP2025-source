#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[10005];
int a[105][105];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    int k=s[1],l=1;
    sort(s+1,s+(n*m)+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                a[i][j]=s[l];
                l++;
            }
        }else{
            for(int i=n;i>=1;i--){
                a[i][j]=s[l];
                l++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==k){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
