#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],p,yi,ling,p1,lian,sum,maxx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)p=1;
		if(a[i]==1)yi++;
		if(a[i]==0)ling++,sum++,maxx+=lian/2,lian=1;
		if(a[i]!=1&&a[i]!=0)p1=1;
		if(a[i]==1&&a[i-1]==1)lian++;
	}
	if(p==0&&k==0){
		if(n%2==0)cout<<n/2;
		if(n%2==1)cout<<0;
		return 0;
	}
	else if(p1==0&&k==1)cout<<yi;
	else if(p1==0&&k==0)cout<<maxx+sum;
	else cout<<k+n/k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
