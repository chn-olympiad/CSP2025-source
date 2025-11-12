#include<bits/stdc++.h>
using namespace std;
int a[5010],n,sum,b[5010],asd;
bool qwe;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	a[0]=0;
	for(int i=0;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=n;i>=3;i--){
		for(int j=0;j<=i-2;j++){
			if(b[i]-b[j]>=2*a[i])
				sum++;
			for(int q=j-1;q>=2;q--){
				for(int p=0;p<=q-1;p++){
					if(b[i]-b[j]+(b[q]-b[p])>=2*a[i]) sum++;
				}
			}
			
		}
	}
	cout << sum;
	return 0;
} 
