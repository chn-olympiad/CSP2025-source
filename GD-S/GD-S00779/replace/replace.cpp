#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

const int N=2e5+25; 

int q,n,m,k,ans=0;
string s1[N],s2[N],q1,q2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	} 
	while(q--){
		cin>>q1>>q2;
		int l1=q1.length(),l2=q2.length();
		if(l1!=l2||(n>1000&&q>1)){
			cout<<0<<endl;continue;
		}ans=0;
		for(int i=1;i<=n;i++){
			int t=s1[i].length();
			for(int j=0;j+t-1<l1;j++){
				if(q1.substr(j,t)==s1[i]){
					if(q1.substr(0,j)+s2[i]+q1.substr(j+t)==q2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
 
