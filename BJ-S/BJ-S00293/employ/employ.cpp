#include<iostream>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long f=1;
	for(int i=1;i<=m;i++){
		f*=i;
		f%=998244353;
	}
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
