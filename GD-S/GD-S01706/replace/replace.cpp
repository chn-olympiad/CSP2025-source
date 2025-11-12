#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string s1,s2,t1,t2;
int l[N],r[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		bool flag=1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]=='b') flag=0;
			else if(flag) l[i]--;
			else r[i]--;
		}
		flag=1;
		for(int j=0;j<s2.size();j++){
			if(s2[j]=='b') flag=0;
			else if(flag) l[i]++;
			else r[i]++;
		}
	}
	cin>>t1>>t2;
	int L1=0,R1=0,L2=0,R2=0;
	bool flag=1;
	for(int i=0;i<=t1.size();i++){
		if(t1[i]=='b') flag=0;
		else if(flag) L1++;
		else R1++;
	}
	flag=1;
	for(int i=0;i<=t2.size();i++){
		if(t2[i]=='b') flag=0;
		else if(flag) L2++;
		else R2++;
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(L1+l[i]==L2&&R1+r[i]==R2) ans++;
	cout<<ans;
	return 0;
} 
