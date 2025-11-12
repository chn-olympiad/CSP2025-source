#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int q,n,a[N][3],mx[N],id[N];
int c[3],t[3];
void work(){
	memset(c,0,sizeof c);
	memset(t,0,sizeof t);
	cin>>n;
	for(int i=1;i<=n;i++){
		mx[i]=0;
		for(int j=0;j<3;j++)cin>>a[i][j],mx[i]=max(mx[i],a[i][j]);
		for(int j=0;j<3;j++)if(a[i][j]==mx[i])id[i]=j;
		c[id[i]]++,t[id[i]]+=a[i][id[i]];
	}
	int ans=0;
	for(int i=0;i<3;i++)ans+=t[i];
	int over=-1;
	for(int i=0;i<3;i++)if(c[i]>n/2)over=i;
	if(~over){
		vector<int>ov;
		for(int i=1;i<=n;i++)
			if(id[i]==over){
				int nw=0;
				for(int j=0;j<3;j++)if(id[i]!=j)nw=max(nw,a[i][j]);
				ov.push_back(a[i][id[i]]-nw);
			}
		sort(ov.begin(),ov.end());
		for(int i=0;i<c[over]-n/2;i++)ans-=ov[i];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>q;
	while(q--)work();
	return 0;
}
