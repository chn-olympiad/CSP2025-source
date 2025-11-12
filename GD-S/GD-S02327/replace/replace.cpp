#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[int(1e4+10)][2],st1,st2;
string sr(string s1,int a,int b){
	string s="";
	for(int i=a;i<=b;i++){
		s+=s1[i];
	}
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=m;i++){
		long long ans=0;
		cin>>st1>>st2;
		for(int j=1;j<=n;j++){
			for(int l=0;l<st1.size()-s[j][0].size()-1;l++){
				int r=l+s[j][0].size();
				if(sr(st1,l,r-l)==s[j][0]){
					if(sr(st1,0,l)+s[j][1]+sr(st1,r,st1.size()-1)==st2){
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
} 
