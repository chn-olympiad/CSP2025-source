#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int f[500010];
int qzh[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		qzh[i] = qzh[i - 1] ^ a[i];
	}
	int h = 0;
	for(int i = 1;i <= n;i++){
		f[i] = f[i - 1];
		for(int j = i;j > h;j--){
			//cout<<(qzh[i] ^ qzh[j - 1])<<' ';
			if((qzh[i] ^ qzh[j - 1]) == k){
				f[i] = max(f[j] + 1,f[i]);
				h = i;
			}
		}
		//cout<<endl;
	}
	cout<<f[n];
	return 0;
}

