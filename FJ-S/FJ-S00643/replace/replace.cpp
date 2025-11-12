#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q,a[N];
string s1,s2;
set<int> s; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int x,y;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b'){
				x=i;
				break;
			}
			if(s2[i]=='b'){
				y=i;
				break;
			}
		}
		a[i]=y-x;
		s.insert(a[i]);
	}
	while(q--){
		cin>>s1>>s2;
		int x,y;
		for(int i=0;i<s1.size();i++){
			if(s1[i]=='b'){
				x=i;
				break;
			}
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]=='b'){
				y=i;
				break;
			}
		}
		if(s.count(y-x)) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	
	return 0;
}

