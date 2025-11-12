#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=210;
int T,n,ans,v[N][4],w[N];
bool A=true,B=true;
void dfs(int s,int x,int y,int z,int res){
	if(s==n+1){
		ans=max(ans,res);
		return;
	}
	if(x+1<=(n>>1))dfs(s+1,x+1,y,z,res+v[s][1]);
	if(y+1<=(n>>1))dfs(s+1,x,y+1,z,res+v[s][2]);
	if(z+1<=(n>>1))dfs(s+1,x,y,z+1,res+v[s][3]);
}
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n,ans=0,A=true,B=true;
        for(int i=1;i<=n;i++){
        	cin>>v[i][1]>>v[i][2]>>v[i][3];
        	if(v[i][2]!=0||v[i][3]!=0)A=false;
        	if(v[i][3]!=0)B=false;
		}
        if(A){
        	for(int i=1;i<=n;i++)
        	w[i]=v[i][1];
        	sort(w+1,w+n+1,cmp);
        	for(int i=1;i<=(n>>1);i++)
        	ans+=w[i];
		} else if(B){
			ans=0;
		} else {
			dfs(1,0,0,0,0);
		}
        cout<<ans<<endl;
    }
    return 0;
}