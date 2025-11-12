#include<bits/stdc++.h>
using namespace std;
int n,k,a[500100],ma=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){	
			int x=a[i],sum=0,f=1;
			if(x==k){
				sum++;
				f=2;
				x=a[i+1];
			}
			for(int j=i+f;j<=n;++j){
				x=x^a[j];
				if(x==k){
					sum++;
					j++;
					x=a[j];
				}
			}
			ma=max(ma,sum);
	}	
	cout << ma;
	return 0;
}
