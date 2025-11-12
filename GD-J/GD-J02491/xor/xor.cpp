#include<bits/stdc++.h>
using namespace std;
#define ing long long
const int N=5e5+10;

int n,k,t,ans;
int a[N];
int f[N];

signed main(){
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	f[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	//	cout<<f[i]<<" ";
	}
	//cout<<endl;
	t=n;
	while(t>=0){
		bool v=0;
	//	cout<<t<<endl;
		for(int j=1;j<=t;j++){
			if((f[t]^f[t-j])==k){
				//cout<<(f[t]^f[t-j]);
			//	printf("%lld-%lld\n",t,t-j+1);
				ans++;
				t=t-j-1;
				v=1;
				//goto s;
				break;
			}
		}
		if(v) continue;
		t--;
	//	s:
			
	}
	cout<<ans;
	return 0;
} 
