#include<bits\stdc++.h>
using namespace std;

int s[500005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
	}
	for (int i=1;i<=n;i++) {
		if (s[i]==k) {
			a++;
		}
		else if ((s[i]^s[i+1])==k&&(i+1)<=n){
			a++;
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}