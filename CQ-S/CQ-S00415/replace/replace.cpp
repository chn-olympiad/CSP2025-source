#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,q;
map<string,string> mp;
string s[N],t[N];
signed main(){
     freopen("replace.in","r",stdin);
     freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	if(q<=10000){
		while(q--){
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=n;i++){
			int k=0,fl=0,zi=0;
			for(int j=0;j<x.size();j++){
				if(x[j]==s[i][k]){
					k++;
				}
				else{
					if(k==s[i].size()){
						fl=1;
						zi=j-1;
						k=0;
					}
					else k=0;
				}
			}
			if(k==s[i].size()){
				fl=1;
				zi=x.size()-1; 
			}
			if(fl){
				int fll=1;
				string xx=x;
				for(int j=zi-s[i].size()+1,l=0;j<=zi&&l<s[i].size();j++,l++){
					xx[j]=t[i][l];
				}
				ans+=(xx==y);
			}
			
		}
		cout<<ans<<"\n";
		}
	}
	else{
		while(q--){
			cout<<0<<"\n";
		}
	}
	
    return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/

