#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n=0,m=0;
	int ans=0;
	cin >> n >> m;
	string qq;
	cin >> qq;
	int a[n] = {};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	char q[n] = {};
	for(int i=0;i<n;i++){
		q[i] = qq[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=n-i-1;j>0;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				swap(q[j],q[j-1]);
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
