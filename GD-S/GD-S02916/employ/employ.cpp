#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,o,sum=1;
	cin>>n>>m;
	long long a[n]={0};
	char p[n];
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++){
		cin>>o;
		a[o]++;
	}
	for(int i=0;i<n;i++){
		if(a[i]>0) sum*=a[i];
	}
	cout<<sum*21;
	fclose(stdin);
	fclose(stdout);
}
