#include <bits/stdc++.h>

using namespace std;

long long ans=0;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	for(int i=0;i<n;i++) cin >>a[i];
	sort(a,a+n);
	if(a[n-1]==1){
		cout <<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		int z=0;
		int max_gui=0;
		int total_gui=0;
		for(int j=i;j<n;j++){
			total_gui+=a[j];
			max_gui=max(max_gui,a[j]);
			if(z>=3&&total_gui>=max_gui*2) ans++;
			z++;
		}
	}
	cout <<ans;
	return 0;
}