#include<bits/stdc++.h> 
using namespace std;
long long n,k,a[500005],ans=0,t1,sum,q;
pair<int,bool> b[1ll<<21];
int main(){
	freopen("xor6.in","r",stdin);
	//freopen("xor1.out","w",stdout);
	cin>>n>>k;
//	cout<<n<<' '<<k<<'\n';
	for(int i=1;i<=n;++i){
		cin>>a[i];
//		cout<<a[i]<<'\n';
		if(a[i]==1)++q;
	}
//	cout<<'\n';	
	b[0]=make_pair(n+1,1);
	for(int i=1;i<=n;++i){
		ans^=a[i];
		 
		if(ans==k||b[ans^k].second&&b[ans^k].first>t1){
			++sum;
//			cout<<i<<' '<<ans<<' '<<b[ans^k].first<<'\n';
			t1=i;
			b[ans]=make_pair(i,1);
			ans=0;
		} 
		else b[ans]=make_pair(i,1);
	}
	cout<<sum;
}

