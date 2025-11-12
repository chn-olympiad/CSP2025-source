#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],b[N],q,z=1;
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
		if(b[i]==k){
			q++;
			z=i+1;
			continue;
		}
		for(int j=z;j<=i;j++){
			if(i!=j) b[j]=b[j]^a[i];
			if(b[j]==k){
				z=i+1;
				q++;
				break;
			}
		}
	}
	cout << q;
}
