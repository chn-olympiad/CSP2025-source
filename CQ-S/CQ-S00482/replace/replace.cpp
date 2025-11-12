#include<bits/stdc++.h>
using namespace std;

const int N=2e5+24;
int n,q,ans;
string s1[N],s2[N],t1,t2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		ans=0;
		cin>>t1>>t2;
		
		for(int i=0;i<t1.length();i++){
			for(int j=1;i<=n;i++){
				bool flag=true;
				for(int k=0;k<s1[j].length();k++) if(t1[i+k]!=s1[j][k]) flag=false;
				if(flag){
					string ts=t1;
					for(int k=0;k<s1[j].length();k++) t1[i+k]=s2[j][k];
					if(t1==t2){
						ans++;
					}
					t1=ts;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
