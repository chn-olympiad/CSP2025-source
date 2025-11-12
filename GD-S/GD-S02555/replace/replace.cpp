#include<iostream>
using namespace std;
const int N=2e5+5;
int n,q,pl[N],pr[N];
string s[N][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int len=s[i][0].size();
		if(s[i][0].size()!=s[i][0].size()){
			i--;n--;
			continue;
		}
		int l=-1,r=s[i][0].size()-1;
		for(int j=0;j<len;j++){
			if(s[i][1][j]!=s[i][0][j]){
				r=j;
				if(l<0) l=j; 
			}
		}
		pl[i]=l;
		pr[i]=r;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n"; 
			continue;
		}
		int l=-1,r=a.size()-1;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				r=i;
				if(l<0) l=i;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(pr[i]-pl[i]!=r-l) continue;
			if(pl[i]>l) continue;
			int f=1,st=l-pl[i];
			for(int j=0;j<s[i][0].size();j++){
				if(s[i][0][j]!=a[st+j]||s[i][1][j]!=b[st+j]){
					f=0;
					break;
				}
			}
			ans+=f;
		}
		cout<<ans<<"\n"; 
	} 
	return 0;
}
