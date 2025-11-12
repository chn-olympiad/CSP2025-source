#include<bits/stdc++.h>
using namespace std;
int m,n;
char s[555];
int c[555];
int ans;
int loser,winner;
void find_employ(int day,int who){
    if(winner==m){
        ans++;
        return;
    }
    if(day>n){
        return;
    }
    if(day>=1){
        if(s[day]=='0'||loser>=c[who]){
            loser++;
            for(int i=1;i<=n;i++){
                find_employ(day+1,i);
            }
            loser--;
        }
        else{
            winner++;
            for(int i=1;i<=n;i++){
                find_employ(day+1,i);
            }
            winner--;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    find_employ(0,0);
    cout<<ans;
}
