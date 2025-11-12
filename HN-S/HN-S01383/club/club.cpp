#include<bits/stdc++.h>
using namespace std;
int t,n,z[100005][5],s[5],ans,tmp;
struct node{
	int z,p;
}g[100005];
bool cmp(node a,node b){
	return a.z<b.z;
}
void solve(){
	cin>>n;
	s[1]=s[2]=s[3]=ans=tmp=0;
	for(int i=1;i<=n;++i){
		cin>>z[i][1]>>z[i][2]>>z[i][3];
		ans+=max(z[i][1],max(z[i][2],z[i][3]));
		if(max(z[i][1],max(z[i][2],z[i][3]))==z[i][1])++s[1],g[i].z=z[i][1]-max(z[i][2],z[i][3]),g[i].p=1;
		else if(max(z[i][1],max(z[i][2],z[i][3]))==z[i][2])++s[2],g[i].z=z[i][2]-max(z[i][1],z[i][3]),g[i].p=2;
		else ++s[3],g[i].z=z[i][3]-max(z[i][1],z[i][2]),g[i].p=3;
	}
	sort(g+1,g+n+1,cmp);
	if(s[1]>n/2)tmp=1;
	if(s[2]>n/2)tmp=2;
	if(s[3]>n/2)tmp=3;
	for(int i=1;i<=n;++i)if(g[i].p==tmp&&s[tmp]>n/2)ans-=g[i].z,--s[tmp];
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}
