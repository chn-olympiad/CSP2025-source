#include<bits/stdc++.h>
using namespace std;

const int N=998244353;
long long n,a[5005],s[5005],f,v[5005],ans,b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[++f]=a[1];
	v[a[1]]++;
	if(v[a[2]]==0) s[++f]=a[2];
	v[a[2]]++;
	if(v[a[1]+a[2]]==0) s[++f]=a[1]+a[2];
	v[a[1]+a[2]]++;
	sort(s+1,s+f+1);
	
	for(int i=3;i<=n;i++){	
		if(s[f]>a[i]){
			for(int j=f;j>=1;j--){
				if(s[j]<=a[i]) break;
				ans=(ans%N+v[s[j]]%N)%N;
			}
		}
		long long t=f;
		for(int j=1;j<=f;j++) b[s[j]]=v[s[j]];
		for(int j=1;j<=t;j++){
			if(v[s[j]+a[i]]==0) s[++f]=s[j]+a[i];
			v[s[j]+a[i]]=(v[s[j]+a[i]]%N+b[s[j]]%N)%N;
		}
		if(v[a[i]]==0) s[++f]=a[i];
		v[a[i]]++;
		sort(s+1,s+f+1);	
//		for(int j=1;j<=f;j++) cout<<s[j]<<" "<<v[s[j]]<<" +++++"<<"\n";
//		cout<<" -----"<<"\n";	
	}	
	
	cout<<ans%N;
	
	
	return 0;
}
