#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[505],v[505],b[505],ans,l;
string s;
void dfs(int x,int fs,int p){
    if(x==n+1){
       if(p>=m){
		   ans++;
	   } 
	   
       //return;
    } 
    for(int i=1;i<=n;i++){
        if(v[i]==0){
           v[i]=1;
           b[x]=i;
           if(fs>=a[i]) dfs(x+1,fs+1,p);
           if(s[x-1]=='0')  dfs(x+1,fs+1,p);
           else dfs(x+1,fs,p+1);
           v[i]=0;
        }
    }
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,0);
    cout<<ans/2-1;
    return 0;
}
