#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],cnt,sum,l[500010],r[500010],rr;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum=0;
		for(int j=i;j>=1;j--){
			sum^=a[j];
			if(sum==k){
				r[++r[0]]=i;
				l[++l[0]]=j;
				break;
			}
		}
	}
	for(int i=1;i<=r[0];i++){
		if(l[i]>rr){
			cnt++;
			rr=r[i];
		}
	}
	cout << cnt;
	return 0;
}