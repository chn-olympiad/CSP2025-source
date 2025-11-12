#include<bits/stdc++.h>
using namespace std;

map<string,int> mapp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mapp[a+b]=1;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		if(a.size()!=b.size()){
			cout<<ans<<endl;
			continue;
		}
		int sum=a.size();
		int s,e=-1;
		for(int i=0;i<sum;i++){
			if(a[i]!=b[i]){
				if(e==-1)s=i;
				e=i;
			}
		}
		for(int i=0;i<sum;i++){
			string x,y;
			cout<<x<<y;
			for(int j=i;j<sum;j++){
				x=x+a[j],y=y+b[j];
				if(mapp[x+y]&&j>=e&&i<=s)ans++;
				//cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
