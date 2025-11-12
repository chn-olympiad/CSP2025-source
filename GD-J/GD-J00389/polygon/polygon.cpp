#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[999999];
int main()
{
	freopen("fre.in","r",stdin);
	freopen("fre.out","w",stdout);
	cin >> n;
	int big=0,bi=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>big){
			big=a[i];
			bi=i;
		}
	} 
	if(n==3){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(bi!=i)ans+=a[i];
		}
		cout <<(big<ans?1:0);
	}
	fclose(stdin);
	fclose(stdout);
} 
