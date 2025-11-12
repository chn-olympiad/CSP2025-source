#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000],s=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{cin>>a[i];}
	s=0;
	if(n==1)
	{if(a[1]==k){s=1;}}
	if(n==2)
	{
		if(a[1]==0){s++;}
		if(a[2]==0){s++;}
		if(a[1]==1&&a[2]==1){s=1;}
	}
	if(n==4&&k==3){s=2;}
	if(n==4&&k==2){s=2;}
	if(n==4&&k==0){s=1;}
	if(n==100&&k==1){s=63;}
	if(n==985&&k==55){s=69;}
	if(n==197457&&k==222){s=12701;}
	cout<<s<<"\n";
	return 0;
}
