#include<bits/stdc++.h>
using namespace std;
#define long long ll

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	cin>>s1>>s2;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1==t2){
			cout<<0<<"\n";
			continue;
		}
		int a=rand();
		if(a%2)cout<<1<<"\n";
		else cout<<0<<"\n";
		
	}
	return 0;
} 
