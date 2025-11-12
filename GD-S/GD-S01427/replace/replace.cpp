#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,q,ans;
string s1[N],s2[N],t1[N],t2[N];

bool check(int qq,int v){
	bool fl=false;
	string x,y,z,ss;
	for(int i=0;i<t1[qq].size();i++){
		if(t1[qq][i]==s1[v][0]){
//			cout<<i<<" "<<qq<<' '<<v<<endl;
			y="";
			for(int j=1;j<s1[v].size();j++){
				y=y+t1[qq][i+j];
				if(t1[qq][i+j]!=s1[v][j]){
					fl=true;
					break;
				}
			}
			if(!fl){
//				cout<<qq<<" "<<v<<endl;
				z="";
				for(int j=i+s1[v].size();j<t1[qq].size();j++){
					z=z+t1[qq][j];
				}
//				cout<<x<<s2[v]<<z<<endl;
				
				ss="";ss=ss+x;ss=ss+s2[v];ss=ss+z;
				
//				cout<<ss<<endl;
				if(ss==t2[qq]){
					return true;
				}
			}
		}
		x=x+t1[qq][i];
	}
	return false;
}

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			if(check(i,j)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
} 
