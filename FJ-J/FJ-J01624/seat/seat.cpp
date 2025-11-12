#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t;
vector<pair<int,int> > v;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=1;
	y=1;
	for(int i=1;i<=n*m;i++){
		cin>>t;
		v.push_back({i,t});
	}
	bool p=1;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(v[i].first==1){
			cout<<x<<" "<<y;
			break;
		}else{
			if(p==1){
				y++;
				if(y==n+1){
					x++;
					y=n;
					p=0;
				}
			}else{
				y--;
				if(y==0){
					x++;
					y=1;
					p=1;
				}
			}
		}
	}
	
	return 0;
}
/*
define int long long
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
system("fc seat.out seat2.ans");
rp++;rp++;rp++;rp++;rp++;rp++;

*/
