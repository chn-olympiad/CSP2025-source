#include<bits/stdc++.h>
using namespace std;
int maxn = -9999;
int h;
int n;
long long ans;
int k;
int a[5010];
int max1(int x,int y,int z){
	int s = max(x,y);
	s = max(s,z);
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		
	} 
	
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			for(int z = j + 1;z <= n;z++){
				if(a[i] + a[j] + a[z] > 2 * max1(a[i],a[j],a[z])) ans++;
			}
		}	
	}
	cout << ans;
	return 0;
}