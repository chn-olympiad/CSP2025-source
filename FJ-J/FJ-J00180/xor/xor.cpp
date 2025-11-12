#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int n,k,la=0;
int a[500010],b[500010];
map<int,int> m;
int ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	m[0]=0;
	for(int i=1;i<=n;i++){
		if(m.count(b[i]^k)){
//			cout<<i<<" "<<m[b[i]^k]<<" "<<la<<endl;
			if(m[b[i]^k]>=la){
//				cout<<i<<endl;
				ans++;	
				la=i;
			}		
		}	
		m[b[i]]=i;
	}
	cout<<ans;
	return 0;
}
