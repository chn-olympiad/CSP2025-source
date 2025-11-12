#include<bits/stdc++.h>
using namespace std;
int n,m,c[20],p[20];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int ans=0;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)p[i]=i;
    do{
        int num=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'&&cnt<c[p[i]])num++;
            else cnt++;
        }if(num>=m)ans++;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}
