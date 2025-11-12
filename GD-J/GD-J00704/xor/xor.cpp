#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,A=1,B=1,cnt_0=0,cnt_1=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) cnt_0++;
		if(a[i]==1) cnt_1++;
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
	}
	if(!k&&A) cout << n/2;
	else if(k<=1&&B){
		if(k==0) cout << cnt_0+cnt_1/2;
		else cout << cnt_1;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int m=0;
				for(int l=i;l<=j;l++) m^=a[l];
				if(m==k){
					ans++;
					i=j+1;
					j=i;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
