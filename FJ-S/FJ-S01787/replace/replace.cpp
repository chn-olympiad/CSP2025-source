#include<bits/stdc++.h>
using namespace std;
string a[200005],a1[200005],b,c;
int fi(string b,string c,string a,string a1){
	if(b.size()!=c.size()){
		return 0;
	}
	if(b.find(a)==c.find(a1)){
		for(int i=0;i<b.find(a);i++){
			if(b[i]!=c[i]) return 0;
		}
		for(int i=b.find(a)+a.size();i<b.size();i++){
			if(b[i]!=c[i]) return 0;
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>a1[i];
	}
	for(int i=1;i<=q;i++){
		cin>>b>>c;
		for(int j=1;j<=n;j++){
			ans+=fi(b,c,a[j],a1[j]);
		} 
		cout<<ans<<endl;
		ans=0;
	}
	
} 
