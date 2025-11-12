#include <bits/stdc++.h>
using namespace std;
long long n,m,diff[510],c[510];
const long long T=998224353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bool flag=true;
	int len=s.size(),cnt0=0,cnt1=0;
	for(int i=0;i<len;i++){
		if(s[i]=='1'){
			diff[i]=1;
			cnt1++;
		}
		else{
			diff[i]=0;
			flag=false;
			cnt0++;
		}
	}
	if(flag){
		long long sum=0;
		for(int i=m;i<=n;i++){
			long long t=1;
			for(int j=1,tmp=n;j<=i;j++,tmp--){
				t*=tmp;
			}
			sum+=t;
			sum%=T;
		}
		cout<<sum<<"\n";
	}
	else if(cnt1<m){
			cout<<0<<"\n";
			return 0;
	}
	else{
		sort(c+1,c+1+n);
		long long sum=1;
		for(int i=1;i<=n;i++){
			if(diff[i]==0){
				for(int j=i+1;j<=n;j++){
					diff[i]--;
				}
			}
			else{
				sum*=(n-i);
				sum%=T;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}