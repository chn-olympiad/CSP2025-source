#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string t1,t2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		string m1,m2,m3,n1,n2,n3;
		for(int i=0;i<t1.size();i++){
			for(int j=i;j<t1.size();j++){
				m1=m2=m3=n1=n2=n3="";
				for(int k=0;k<t1.size();k++){
					if(k<i) m1+=t1[k],n1+=t2[k];
					if(k>=i&&k<=j) m2+=t1[k],n2+=t2[k];
					if(k>j) m3+=t1[k],n3+=t2[k];
				}
				
				if(m1==n1&&m3==n3){
					for(int k=1;k<=n;k++){
						if(m2==s[k][0]&&n2==s[k][1]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
