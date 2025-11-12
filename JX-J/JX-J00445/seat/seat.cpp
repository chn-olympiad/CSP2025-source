#include<bits/stdc++.h>
using namespace std;

int n,m,p;
int a[105];
bool f[13][13];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    p=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            p=n*m+1-i;
            break;
        }
    }
    int cnt=1;int j=1;
    for(int i=1;i<=m;){
        for(j;j<=n&&j>=1;j+=cnt){
            if(p>1) p--;
            else{
                cout<<i<<" "<<j;
                return 0;
            }
        }
        i++;
        if(i%2==0){
            cnt=-1;
            j=j-1;
        }else{
            cnt=1;
            j=j+1;
        }
    }
    return 0;
}
