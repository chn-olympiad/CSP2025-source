#include<bits/stdc++.h>
#define N 5000005
using namespace std;
const int mod=10000009;
int n,q;
map<string,string> p;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		p[a]=b;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		if(a.size()==1){
			if(p[a]!=b){
				cout<<"0"<<"\n";
			}
		}
		int l=a.size(),ans=0;
		for(int i=0;i<l;i++){
			string s;
			for(int j=i;j<l;j++){
				string x,y,z;
				if(i>0) x=a.substr(0,i);
				y=a.substr(i,j-i+1);
				if(j<l-1)z=a.substr(j+1,l-j);
				s=x+p[y]+z;
				cout<<x<<" "<<y<<" "<<z<<" "<<s<<"\n";
				if(s==b) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
