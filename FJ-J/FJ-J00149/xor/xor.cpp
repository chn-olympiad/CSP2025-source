#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k,a[500005],c[500005],f[500005],o;

void _work(){
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int j=i;j>=1;j--){
			int h=c[i]^c[j-1];
			//cout << i<<' '<<j<<' '<<h<<'\n';
			if(h==k){
				f[i]=max(f[i],f[j-1]+1);
				break;
			}
		}
		//cout << f[i];
	}
	cout << f[n];
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	o=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		c[i]=c[i-1]^a[i];
		o=max(o,a[i]);
	}
	_work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

