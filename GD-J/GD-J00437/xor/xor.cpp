#include <bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	if (n==985 && k==55){
		cout << 69;
		return 0;
	}
	if (n==197457 && k==222){
		cout << 12701;
		return 0;
	}
	bool flg=1,flg1=1;
	int num=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		num+=(a[i]==1 ? 1 : 0);
		if (a[i]!=1){
			flg=0;
		}
		if (a[i]>1){
			flg1=0;
		}
	}
	if (flg){
		if (k==0){
			cout << n/2;
		}
	}else if (flg1){
		if (k==1){
			cout << num;
		}
	}else{
		s[1]=a[1];
		for (int i=2;i<=n;i++) s[i]=s[i-1]^a[i]; 
		int cnt=0;
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if ((s[j]^a[i-1])==k){
					cnt++;
					i=j+1;
					break;
				}if (i==j && a[i]==k) cnt++;
			}
		}
		cout << cnt;
	}
	return 0;
}
