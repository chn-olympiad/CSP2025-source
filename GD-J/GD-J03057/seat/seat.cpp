#include<bits/stdc++.h>
using namespace std;
int n,m,t,a;
pair<int,int>next(pair<int,int>p){
	if(p.first%2==1){
		p.second++;
		if(p.second>n){
			p.second--;
			p.first++;
		}
	}
	else{
		p.second--;
		if(p.second==0){
			p.second++;
			p.first++;
		}
	}
	return p;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	vector<int>v(n*m);
	for(int i=0;i<n*m;i++)cin>>v[i];
	t=v[0];
	sort(v.begin(),v.end(),[](int a,int b){
		return a>b;
	});
	a=abs(distance(find(v.begin(),v.end(),t),v.begin()));
	pair<int,int>p={1,1};
	for(int i=0;i<a;i++){
		p=next(p);
	}
	cout<<p.first<<' '<<p.second;
}
