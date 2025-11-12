#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,k,cnt,a[N],b[N],tot;//前缀异或 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i] = b[i-1]^a[i];
//		cout << b[i] << " ";
	}
//	cout << k;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			tot=i;
//			cout << tot <<" 1\n";
		} else {
			if(tot+1==i)continue;
			for(int j=tot+1;j<i;j++){
				if(int(b[i]^b[j-1])==k){
					cnt++;
//					cout << (b[i]^b[tot]==k);
					tot=i;break;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}