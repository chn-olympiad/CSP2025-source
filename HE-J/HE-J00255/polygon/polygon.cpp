#include<bits/stdc++.h>
using namespace std;
long long m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	if(n==1 || n==2) cout<<"0";
	if(n == 3) cout<<"1";
	if(n>3){
		for(int i=1;i<=n;i++){
			m *= i;
		}
		printf("lld",m);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
