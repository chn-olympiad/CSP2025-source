#include<bits/stdc++.h>
using namespace std;
int s[105];
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n*m;i++) cin>>s[i];
    int tot=s[1];
    sort(s+1,s+n*m+1,cmp);
    //for(int i=1;i<=n*m;i++) cout<<s[i]<<" ";
    //cout<<endl;
    cnt=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2!=0){
                if(s[cnt]==tot){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                } 
                cnt++;
            }else{
                if(s[cnt]==tot){
                    cout<<i<<" "<<n-j+1<<endl;
                    return 0;
                }
                cnt++;
            }
        }
    }
    return 0;
}