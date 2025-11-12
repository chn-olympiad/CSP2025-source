#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll c=0,s=0;
string w;
ll p[501];
ll a[501];
map<int,int> ma;
bool f[501]={};
ll mod=998244353;
void se(int x){
	if(x>=m){
		s++;
		s%=mod;
		return;
	}
	int u=0;
	list<int> q1,q2;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			if(a[x+1]==0){
				f[i]=1;
				u++;
				c++;
				q1.push_back(i);
				continue;
			}else{
				if(c<p[i]){
					q2.push_back(i);
				}else{
					
				}
				
			}
		}
	}
	while(!q2.empty()){
		f[q2.front()]=1;
		q2.pop_front();
		se(x+1);
		f[q2.front()]=0;
	}
	while(!q1.empty()){
		f[q1.front()]=0;
		q1.pop_front();
	}
	c-=u;
	return;
}
void solve(){
	cin>>n>>m;
	cin>>w;
	for(int i=0;i<w.size();i++){
		if(w[i]=='1') a[i+1]=1;
		else a[i+1]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ma[p[i]]++;
	}
	se(0);
	cout<<s;
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	solve();
	
	return 0;
}
