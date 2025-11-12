#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,z,s,x;
}s[100005];

int t,n,ans;
bool cmp(node a,node b){
	return abs(a.a-a.s)>abs(b.a-b.s);
}
int d[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		d[1]=d[2]=d[3]=0;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=c&&b>=c)s[i].a=a,s[i].z=1,s[i].s=b,s[i].x=2;
			else if(a>=b&&c>=b)s[i].a=a,s[i].z=1,s[i].s=c,s[i].x=3;
			else s[i].a=b,s[i].z=2,s[i].s=c,s[i].x=3; 
		}sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(d[s[i].z]==n/2)ans+=s[i].s,d[s[i].x]++;
			else if(d[s[i].x]==n/2)ans+=s[i].a,d[s[i].z]++;
			else if(s[i].a>=s[i].s)ans+=s[i].a,d[s[i].z]++;
			else ans+=s[i].s,d[s[i].x]++;
		}cout<<ans<<'\n';
	}
	return 0;
}