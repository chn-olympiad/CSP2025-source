#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	unsigned long long res=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		res*=i;
		res%=998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

