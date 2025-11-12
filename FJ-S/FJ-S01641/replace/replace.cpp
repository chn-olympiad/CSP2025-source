#include<bits/stdc++.h>
using namespace std;
string t1,t2,s1,s2;
int n,q,a[200001],b[200001],c[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		int tt1=0,tt2=0;
		int t=t1.size();
		for(int j=0;j<=t;j++){
			if(t1[j]=='b')tt1=j;
			if(t2[j]=='b')tt2=j;
		}
		a[i]=tt1-tt2;
		c[i]=tt1;
		b[i]=t;
	}
	while(q--){
		cin>>s1>>s2;
		int ss1=0,ss2=0,ans=0,s=s1.size();
		for(int j=0;j<=s;j++){
			if(s1[j]=='b')ss1=j;
			if(s2[j]=='b')ss2=j;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==ss1-ss2&&c[i]<=ss1&&(b[i]-c[i])<=(s-ss1))ans++;
		}
		cout<<ans<<endl;
	}
}
