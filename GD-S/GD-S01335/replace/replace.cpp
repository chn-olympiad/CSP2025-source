#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

string s1[100005],s2[100005];
int n,q;	
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string sa,sb,ssa,ssb;
		int ans=0;
		cin>>ssa>>ssb;
		for(int i=1;i<=n;i++){
			sa=ssa,sb=ssb;
			int t1=-1,t2=-1;
			t1=sa.find(s1[i],0);
			if(t1!=string::npos){
				string x=sa.substr(0,t1),z=sa.substr(t1+s1[i].size(),sa.size());
				sa=x+s2[i]+z;
				if(sa==sb)ans++;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
} 



