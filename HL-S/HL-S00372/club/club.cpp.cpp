#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int sum=0;
		int n;
		cin>>n;
		for(int w=0;w<n;w++){
			int a[n];
			cin>>a[0]>>a[1]>>a[2];
			int maxs=max(max(a[0],a[1]),a[2]);
			sum+=maxs;
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}