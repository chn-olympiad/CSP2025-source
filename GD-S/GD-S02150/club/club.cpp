#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll rs=0,w=1;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')w=-1,c=getchar();
	while('0'<=c&&c<='9'){
		rs=rs*10+c-'0';c=getchar();
	}
	return rs*w;
}
const ll N=1e5+10;
ll a[N][4];
bool cmp1(ll u,ll v){
	return a[u][1]-max(a[u][2],a[u][3])>a[v][1]-max(a[v][2],a[v][3]);
}
bool cmp2(ll u,ll v){
	return a[u][2]-max(a[u][1],a[u][3])>a[v][2]-max(a[v][1],a[v][3]);
}
bool cmp3(ll u,ll v){
	return a[u][3]-max(a[u][1],a[u][2])>a[v][3]-max(a[v][2],a[v][1]);
}
vector<ll>cy[4];
ll n;
void work(){
	for(ll i=1;i<=3;i++)cy[i].clear();
	n=read();
	ll as=0;
	for(ll i=1;i<=n;i++){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])cy[1].push_back(i);
		else if(a[i][2]>=a[i][3])cy[2].push_back(i);
		else cy[3].push_back(i);
	}
	if(cy[1].size()>n/2){
		sort(cy[1].begin(),cy[1].end(),cmp1);
		for(ll i=n/2;i<cy[1].size();i++){
			ll id=cy[1][i];
			if(a[id][2]>=a[id][3])cy[2].push_back(id);
			else cy[3].push_back(id);
		}
	}else if(cy[2].size()>n/2){
		sort(cy[2].begin(),cy[2].end(),cmp2);
		for(ll i=n/2;i<cy[2].size();i++){
			ll id=cy[2][i];
			if(a[id][1]>=a[id][3])cy[1].push_back(id);
			else cy[3].push_back(id);
		}
	}else{
		sort(cy[3].begin(),cy[3].end(),cmp3);
		for(ll i=n/2;i<cy[3].size();i++){
			ll id=cy[3][i];
			if(a[id][1]>=a[id][2])cy[1].push_back(id);
			else cy[2].push_back(id);
		}
	}
	for(ll i=0;i<n/2;i++){
		if(cy[1].size()>i)as+=a[cy[1][i]][1];
		if(cy[2].size()>i)as+=a[cy[2][i]][2];
		if(cy[3].size()>i)as+=a[cy[3][i]][3];
	}
	cout<<as<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t=read();while(t--)work();
}
/*
1
2
10 9 8
4 0 0
*/
