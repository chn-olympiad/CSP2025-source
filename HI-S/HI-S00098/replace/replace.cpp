#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans1=0,ans2=0;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>q;
	while(q--){
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			ans1+=(int(s1[i]));
			ans2+=(int(s2[i]));
		}
		if(ans1==ans2){
			cout<<0<<endl;
		}	 
	}
	return 0;
} 
