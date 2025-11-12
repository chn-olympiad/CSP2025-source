#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int u = 0;
	int a[n-1];
	for(int y = 0;y < n; y++){
		cin>>a[y];
	}for(int y = 0;y <= n;y++){
		for(int x = y + 1;x<=n;x++){
			for(int z = y + 2;z<=n;z++){
				for(int c = y+3;c<=n;c++){
					if(a[y]+a[x]+a[z]+a[c]>a[y] and a[y]+a[x]+a[z]+a[c]>a[x] and a[y]+a[x]+a[z]+a[c]>a[z] and a[y]+a[x]+a[z]+a[c]>a[c]){
							u++;
					}
				}
			}
		}
	}cout<<u<<endl;
	return 0;
}
