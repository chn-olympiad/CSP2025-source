#include<cstdio>
#include<iostream>
using namespace std;
const int N=5e5+10;
int n,k;
int cnt;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)cnt++;
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
