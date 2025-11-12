#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long 
int a[100010][10];
set<pair<int,int>>st1,st2,st3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		st1.clear(),st2.clear(),st3.clear();
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2],a[i][3]=max(a[i][0],max(a[i][1],a[i][2]));
		for(int i=1;i<=n;i++){
			if(a[i][0]==a[i][3])st1.insert({a[i][0]-max(a[i][1],a[i][2]),i});
			else if(a[i][1]==a[i][3])st2.insert({a[i][1]-max(a[i][0],a[i][2]),i});
			else if(a[i][2]==a[i][3])st3.insert({a[i][2]-max(a[i][0],a[i][1]),i});
		}
		while((int)st1.size()>n/2){
			pair<int,int> now=(*st1.begin());
			int i=now.second;
			if(a[i][1]>a[i][2])st2.insert({0,i});
			else st3.insert({0,i});
			st1.erase(st1.begin());
		}
		while((int)st2.size()>n/2){
			pair<int,int> now=(*st2.begin());
			int i=now.second;
			if(a[i][0]>a[i][2])st1.insert({0,i});
			else st3.insert({0,i});
			st2.erase(st2.begin());
		}
		while((int)st3.size()>n/2){
			pair<int,int> now=(*st3.begin());
			int i=now.second;
			if(a[i][0]>a[i][1])st1.insert({0,i});
			else st2.insert({0,i});
			st3.erase(st3.begin());
		}
		ll ans=0;
		for(auto i:st1)ans+=a[i.second][0];
		for(auto i:st2)ans+=a[i.second][1];
		for(auto i:st3)ans+=a[i.second][2];
		cout<<ans<<endl;
	}
	return 0;
} 
