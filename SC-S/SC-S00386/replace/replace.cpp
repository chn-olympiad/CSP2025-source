#include<bits/stdc++.h>
using namespace std;
string s1[10005],s2[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		long long ans=0;
		string t1,t2;
		cin>>t1>>t2;
		string cun=t1;
		for(int j=1;j<=n;j++){
			for(int i=0;i<t1.size()-s1[j].size()+1;i++){
				t1=cun;
				bool f=0;
				for(int k=i;k<=i+s1[j].size()-1;k++){
					if(t1[k]!=s1[j][k-i]){
						f=1;
					}
				}
				if(f==0){
				for(int k=i;k<=i+s1[j].size()-1;k++){
					t1[k]=s2[j][k-i];
				}	
				if(t1==t2){
				ans++;
			}
				}
				
			}	
			
		}
		cout<<ans<<'\n';
	}
	return 0;
} 