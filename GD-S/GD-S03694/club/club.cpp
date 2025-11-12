#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m,k,a[4],b[4],num=0;
	cin >>t;
	for(int i=0;i < t;i++){
		cin >>n;
		for(int j=0;j < 3;j++){ 
			b[j] = 0;
		}
		num = 0;
		for(int p=0;p < n;p++){
			m = 0;
			k = 0;
			for(int j=0;j < 3;j++){ 
				cin >>a[j];
				if(a[j] > m){
					k=j;
				}
				m = max(a[j],m);
			}
			if(b[k] <= n/2){
				b[k]++;
				num += a[k];
			}
		}
		cout <<num<<endl;
	}
	return 0;
}
