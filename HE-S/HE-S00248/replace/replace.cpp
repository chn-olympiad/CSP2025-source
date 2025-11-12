#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int sum=0;
		for(int i=1;i<=n;i++){
			int x=s.find(s1[i]);
			if(x!=-1)sum++;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
