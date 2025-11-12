#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[100000];
string func(int a,int n){
	string t="";
	while(a){t+=a%2+'0'; a/=2;}
	while(t.size()<n) t+='0';
	reverse(t.begin(),t.end());
	return t;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n<=20){
		int t=pow(2,n)-1;
		for(int i=1; i<=t; i++){
			string s=func(i,n);
			s=" "+s;
			int maxx=0,sum=0;
			for(int j=1; j<s.size(); j++){
				if(s[j]=='1'){
					maxx=max(maxx,a[j]);
					sum+=a[j];
				}
			}
			maxx=maxx*2;
			if(sum>maxx) ans++;
		}
		cout<<ans;
	}
	else{
		int sum=0,cnt=0;
		for(int i=1; i<=n; i++){
			if(a[i]==1) sum++;
			if(a[i]==0) cnt++;
		}
		sum=(sum*(sum-1)*(sum-2))/6;
		sum%=998244353;
		sum=sum*cnt;
		sum%=998244353;
		cout<<sum;
		return 0;
	}
	return 0;
}
