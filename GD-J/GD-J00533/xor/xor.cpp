#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,ans;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1;
	while(l<=n){
		bool flag=0;
		int index=0x3f3f3f;
		for(int i=l;i<=n;i++){//区间起点 xx
			int sum=0;
			for(int j=i;j<=n;j++){//区间终点 y
				sum=sum^a[j];
				if(sum==k){
					//cout<<l<<' '<<index<<endl;
					flag=true;
					index=min(index,j);
				}
			}
		}
		if(!flag){
			break;
		}else{
			ans++;
			l=index+1;
		}
	}
	cout<<ans;
	return 0;
}
