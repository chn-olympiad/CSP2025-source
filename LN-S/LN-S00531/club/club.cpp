#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int s[100005];
int a,b,c;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t>>n;

    for(int j=1;j<=n;j++){
        cin>>s[j];
    }
    int maxx=max(s[a],s[b],s[c]);
    int ans=maxx*n;
    cout<<ans;





return 0;
}
