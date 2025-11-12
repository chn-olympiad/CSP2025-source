#include<bits/stdc++.h>
using namespace std;
int a[500005];
int mx=0;int n,k;
void dt(int l,int cnt){
	if(l > n) {
		mx=max(mx,cnt);
		return;
	}
	for(int i=l;i<=n;i++){
		int num = a[l];
		for(int j=l+1;j<=i;j++){
			num=num^a[j];
		}
		if(num == k){
			dt(i+1,cnt+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dt(1,0);
	printf("%d",mx);
	return 0;
}
