#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
const int N=2e5+10;
string s1[N],s2[N];
// world is a big galgame
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++){
cin>>s1[i]>>s2[i];
}
for(int i=1;i<=q;i++){
	int ans=0;
	string s,t;
	cin>>s>>t;
	int cnt=0;
	string kl;
for(int j=1;j<=n;j++){
	int k=s.find(s1[j]);
	while(k!=-1){
	kl=s;
//	cout<<s1[j]<<endl;
    kl.replace(k,s1[j].size(),s2[j]);
	//cout<<kl<<endl;	
	if(kl==t){
		ans++;
}
k=s.find(s1[j],k+1);
	}	
}
	cout<<ans<<endl;
}

	
	
	
	return 0;
}
