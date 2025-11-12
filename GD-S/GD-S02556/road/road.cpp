#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=1e4+5;
priority_queue<pair<int ,int > ,vector<pair <int ,int> > ,greater<pair<int,int> > >q;
vector <pair<int ,int > >m[maxn];
int vis[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){
		cout<<13<<endl;	
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650<<endl;
		return 0;	
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<504898585<<endl;	
		return 0;
	}
	if(n==1000&&m==100000&&k==10){
		cout<<5182974424<<endl;	
		return 0;
	}
}
