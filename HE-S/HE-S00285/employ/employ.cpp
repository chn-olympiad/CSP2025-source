#include<bits/stdc++.h>
using namespace std;
long long n,m,b[100001],num=1,num1=1,num2=1;
char a[100001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int k=m;
	while(m>=1){
		num*=m;
		m--;
	}
	for(int i=1;i<=k;i++){
		num1*=n;
		n--;
	}
	while(k>=1){
		num2*=k;
		k--;
	}
	cout<<num*num1/num2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
