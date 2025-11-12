#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N =1e6+10;
map<string ,int> mp;
int n,q,len,vis[N],revis[N];
string t1,t2;
int Slove(){
	int ans=0,len=t1.size();
	bool f=true;
	for(int i=0;i<len;i++){
		vis[i]=0;
		if(t1[i]!=t2[i])	f=false;
		vis[i]=f;
	}
	f=true;
	for(int i=len-1;i>=0;i--){
		revis[i]=0;
		if(t1[i]!=t2[i])	f=false;
		revis[i]=f;
	}
	
	for(int i=0;i<len;i++){
		string T1,T2; T1.clear(),T2.clear();
		for(int j=i;j<len;j++){
			T1+=t1[j],T2+=t2[j];
			if((j<len-1&&revis[j+1]==false)||(i>0&&vis[i-1]==false))	continue;
			ans+=mp[T1+'#'+T2];
			
			
		}
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2,s3; cin>>s1>>s2,s3=s1+'#'+s2;
		mp[s3]++;
	}	
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size())	{cout<<0<<endl; continue;}
		cout<<Slove()<<endl;
	}
	return 0; 
}

