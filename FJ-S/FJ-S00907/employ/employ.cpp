#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[505];
int sum[505];
long long jc(int n){
	long long res=1;
	for(int i=1;i<=n;i++)
		res=res*i%mod;
	return res;
}
int qpl[15];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		qpl[i]=i;
		if(c[i]==0)
			cnt++;
	}
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+((s[i]-'0')^1);
	if(m==n){
		if(cnt){
			cout<<0;
			return 0;
		} 
		if(sum[n]){
			cout<<0;
			return 0;
		}
		cout<<jc(n);
		return 0;
	}
	int ans=0;
	int ymr=0;
	int cntt=0;
	for(int j=1;j<=n;j++){
		if(c[qpl[j]]<=ymr){
			ymr++;
			continue;
		}
		if(s[j]=='1')
			cntt++;
		else
			ymr++;
	}
	if(cntt>=m)
		ans++;
	while(next_permutation(qpl+1,qpl+n+1)){
		int ymr=0;
		int cntt=0;
		for(int j=1;j<=n;j++){
			if(c[qpl[j]]<=ymr){
				ymr++;
				continue;
			}
			if(s[j]=='1')
				cntt++;
			else
				ymr++;
		}
		if(cntt>=m)
			ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
