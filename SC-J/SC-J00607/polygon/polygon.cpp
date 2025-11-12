#include<bits\stdc++.h>
using namespace std;

int s[5010];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a=0;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	for (int i=1,j=3;j<=n,i<=n;j++) {
		int ans=0,mx=0;
		for (int k=i;k<=j;k++) {
			ans+=s[k];
			mx=max(mx,s[k]);
		}
		if (ans>2*mx) {
			a++;
		}
		else {
			i++;
			if (j-i>3) {
				j--;
			}
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}