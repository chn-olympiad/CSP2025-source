#include<bits/stdc++.h>
using namespace std;

map<string,long long>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a, b;
		cin>>a>>b;
		int l,r;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				l=j;
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				r=j;
				break;
			}
		}
		string x="",y="";
		for(int j=l;j<=r;j++){
			x+=a[j];
			y+=b[j];
		}
		x+=y;
		mp[x]++;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0"<<endl;
			continue; 
		}
		int l,r;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				l=j;
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				r=j;
				break;
			}
		}
		string x="",y="";
		for(int j=l;j<=r;j++){
			x+=a[j];
			y+=b[j];
		}
		x+=y;
		cout<<mp[x]<<endl;
	}
	return 0;
} 
