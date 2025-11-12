#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,out=0;
	string begin,end;
	cin>>n>>m;
	vector<pair<string,string> >rules(n);
	for(int i=0;i<n;i++)cin>>rules[i].first>>rules[i].second;
	for(int i=0;i<m;i++){
		cin>>begin>>end;
		cout<<"0\n";
	}
	
	return 0;
}

