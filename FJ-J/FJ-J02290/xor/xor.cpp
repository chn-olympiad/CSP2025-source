#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k;
int a[500100];
int mx=0;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int la=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		int num=a[i];
		if(num==k){
			sum++;
			la=i;
		}
		else for(int j=i-1;j>la;j--){
			num=num^a[j];
			if(num==k){
				la=i;
				sum++;
				break;
			}
		}
		mx=max(mx,sum);
	}
	cout<<mx;
	
	return 0;
}
