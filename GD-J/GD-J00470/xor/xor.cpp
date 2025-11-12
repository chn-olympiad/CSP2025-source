#include<bits/stdc++.h>
using namespace std;
int n,k,z[500005],p[1100005],sum[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>z[i];
		sum[i]=sum[i-1]^z[i];
	} 
	int lst=0;
	for(int i=1;i<=n;i++){
		int a=k^sum[i];
		if(lst==0&&a==0){
			lst=i;
			ans++;
		}else if(p[a]&&p[a]>=lst){
			lst=i;
			ans++;
		}
		p[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}

