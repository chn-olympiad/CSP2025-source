#include <bits/stdc++.h>
using namespace std;
string zichuan(string s,int i,int j){
	string ans="";
	for(int k=i;k<=j;k++){
		 ans+=s[k];
	}	
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[10005],b[10005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		
	}
	for(int k=0;k<q;k++){
		int ans=0;
		string x,y;
		cin>>x;
		cin>>y;
		for(int i=0;i<x.size();i++){
			for(int j=i;j<x.size();j++){
				for(int l=0;l<n;l++){
					if(zichuan(x,i,j)==a[l] and zichuan(y,i,j)==b[l]){
						if(zichuan(x,0,i-1)==zichuan(y,0,i-1) and zichuan(x,j+1,x.size()-1)==zichuan(y,j+1,y.size()-1))
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
