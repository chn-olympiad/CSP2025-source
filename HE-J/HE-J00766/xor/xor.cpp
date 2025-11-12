#include <bits/stdc++.h>
using namespace std;
int n,k,a[200005],b[200005],num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i-1]+a[i];
	}
	if(n<=9){
	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			if(b[r]-b[l-1]==k){
				num++;
			}
		}
	}
	}
	else{
		for (int l=1;l<=n;l++){
			for (int r=l;r<=n;r++){
				int shuzi=a[l];
				for (int i=l;i<=r;i++){
					shuzi=a[i]&shuzi;
				}
				if(shuzi==k){
					num++;
				}
			}
		}
	}
	cout << num;
	return 0;
}
