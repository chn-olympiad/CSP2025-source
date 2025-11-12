#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],tib[5005]={0},s=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=3;i<=n;i++){
		for(int f=0;f<i;f++){
			tib[f]=f+1;
		}
		while(tib[0]<=n-i+1){
			while(tib[i-1]<=n){
				int sum=0,maxa=0;
				for(int q=0;q<i;q++){
		 	 		sum=sum+a[tib[q]-1];
		 	 		maxa=max(maxa,a[tib[q]-1]);
		 	 	}
		 	 	if(sum>maxa*2){
		 	 		s++;
		 	 	}
		 	 	tib[i-1]++;
			}
			for(int l=i-1;l>=0;l--){
				if(tib[l]<=n){
					tib[l]++;
					for(int to=l+1;to<n;to++){
						tib[to]=tib[to-1]+1;
					}
					break;
				}
			}
		}
	}
	cout << s%998244353;
	return 0;
}