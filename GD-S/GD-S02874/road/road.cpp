#include<bits/stdc++.h>
using namespace std;
struct vilg{
	int imp;
	int fix[10005];
	bool cha;
}v[15];
struct city{
	int ct1,ct2;
	int fee;
}c[1000005];
int s[10005][10005]={0};
bool cmp(city a,city b){
	return a.fee<b.fee;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b>>c[i].fee;
		c[i].ct1=a-1;
		c[i].ct2=b-1;
	}
	sort(c,c+m,cmp);
	for(int i=0;i<k;i++){
		cin>>v[i].imp;
		for(int j=0;j<n;j++){
			cin>>v[i].fix[j];
		}
		v[i].cha=0;
	}
	long long ans=0;
	for(int i=0;i<m;i++){
		long long cost=INT_MAX,gz;
		for(int j=0;j<k;j++){
			long long money=v[j].fix[c[i].ct1]+v[j].fix[c[i].ct2];
			if(!v[j].cha)money+=v[j].imp;
			if(cost>money){
				cost=money;
				gz=j;
			}
		}
		if(s[min(c[i].ct1,c[i].ct2)][max(c[i].ct1,c[i].ct2)]!=0){
			if(s[min(c[i].ct1,c[i].ct2)][max(c[i].ct1,c[i].ct2)]<cost)continue;
			else s[min(c[i].ct1,c[i].ct2)][max(c[i].ct1,c[i].ct2)]=cost;
		}else{
			s[min(c[i].ct1,c[i].ct2)][max(c[i].ct1,c[i].ct2)]=cost;
		}
		if(cost<=c[i].fee){
			ans+=cost;
			v[gz].cha=1;
		}else{
			ans+=c[i].fee;
		}
	}
	cout<<ans;
	return 0;
}
