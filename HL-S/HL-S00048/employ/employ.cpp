#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long c[500],pow1=1,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(unsigned long long i=m;i<=n;i++){
		pow1=1;
		for(unsigned long long j=2;j<=i;j++){
			pow1*=j;
		}
		sum+=pow1;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
