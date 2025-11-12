#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,a[N],b[N],c[N],p[N];
void work(){
	cin>>n;
	int c1=0,c2=0,c3=0,res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		int t=max(a[i],max(b[i],c[i]));
		if(a[i]==t)c1++,p[i]=1;
		else if(b[i]==t)c2++,p[i]=2;
		else c3++,p[i]=3;
		res+=t;
	}
	vector<int>v;v.clear();
	if(c1>n/2){
		int pos=c1-n/2;
		for(int i=1;i<=n;i++){
			if(p[i]!=1)continue;
			v.push_back(a[i]-max(b[i],c[i]));
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=pos;i++)res-=v[i-1];
	}
	else if(c2>n/2){
		int pos=c2-n/2;
		for(int i=1;i<=n;i++){
			if(p[i]!=2)continue;
			v.push_back(b[i]-max(a[i],c[i]));
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=pos;i++)res-=v[i-1];
	}
	else if(c3>n/2){
		int pos=c3-n/2;
		for(int i=1;i<=n;i++){
			if(p[i]!=3)continue;
			v.push_back(c[i]-max(a[i],b[i]));
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=pos;i++)res-=v[i-1];
	}
	cout<<res<<"\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)work();
	return 0;
}
