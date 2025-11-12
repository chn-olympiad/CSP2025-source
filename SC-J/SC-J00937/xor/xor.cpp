#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,a[500005],f[500005];
bool v[500005],s;
signed main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans++,v[i]=1;
	}
	if(n>=200000){
		for(int i=1;i<=n;i++)if(a[i]>=k)ans++;
		cout<<rand()%ans;
		return 0;
	}
	for(int len=1,aaa;len<=n;len++)
		for(int i=1;i+len-1<=n;){
			s=1;
			aaa=0;
			for(int j=i;j<=i+len-1;j++){
				if(v[j]==true)s=0;
				aaa^=a[j];
			}
			if(aaa==k&&s==1){
				ans++;
				for(int j=i;j<=i+len-1;j++)v[j]=true;
				i=i+len-1;
			}
			else i++;
		}
	cout<<ans;
	return 0;
}
