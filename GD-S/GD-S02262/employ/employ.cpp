#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,cnt=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cnt=n;
	for(int i=n-1;i>1;i--){
		cnt*=i-1;
		cnt%=998;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
} 
