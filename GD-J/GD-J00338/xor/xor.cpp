#include<bits/stdc++.h>//30
using namespace std;
const int N=5e5+5;
int n, a[N], k;
int cnt, ans;
int cnt1, maxn;
bool flag=1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		if(a[i]!=1)
			flag=0;
		if(a[i]==1)
			cnt1++;
		maxn=max(maxn, a[i]);
	}
	if(n==1){
		cout<<(a[1]==k)<<endl;
		return 0;
	}
	if(maxn<k){
		cout<<0<<endl;
		return 0;
	}
	if(flag){
		if(k)
			cout<<cnt1<<endl;
		else{
			ans=cnt1/2;
			for(int i=1, l=0; i<=n; i++){
				l^=a[i];
				if(!l){
					cnt++;
					l=0;
				}
			}
			cout<<max(ans, cnt)<<endl;
		}
		return 0;
	}
	for(int i=1; i<=n; i++){
		cnt=0;
		for(int j=i, l=0; j<=n; j++){
			l^=a[j];
			if(k==l){
				cnt++;
				l=0;
			}
		}
		for(int j=i-1, l=0; j>0; j--){
			l^=a[j];
			if(l==k){
				cnt++;
				l=0;
			}
		}
		ans=max(ans, cnt);
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
