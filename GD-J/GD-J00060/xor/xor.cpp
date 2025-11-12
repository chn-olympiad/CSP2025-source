#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a,num=0,s=0,p[2000001];
	memset(p,128,sizeof(p));
	cin>>n>>k;
	p[k]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		s^=a;
		num=max(num,p[s]+1);
		p[s^k]=max(p[s^k],num);
	}
	cout<<num;
	return 0;
}
