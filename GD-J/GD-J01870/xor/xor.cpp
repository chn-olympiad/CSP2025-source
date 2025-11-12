#include<bits/stdc++.h>
using namespace std;
int n,k,x[2000005],a[2000005],last,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i] ^= a[i-1];
		if((x[k^a[i]]&&x[k^a[i]]>=last)){
			last = i;
			cnt ++;
		}else if((k^a[i])==0&&last==0){
			last = i;
			cnt ++;
		}
//		cout << a[i] << ' ' << (k^a[i]) << ' ' <<cnt << endl;
		x[a[i]] = i;
	}
	cout << cnt;
	return 0;
}
