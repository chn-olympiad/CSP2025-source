#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,ls,hs;
	cin>>n>>m;
	int c=n*m;
	long long a[c+5]={};
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	int xr=a[1],wz;
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;i++){
		if(a[i]==xr){
			wz=i;
		}
	}
	if(wz%m!=0) ls=wz/m+1;
	else ls=wz/m;
	if(ls%2==0){
		if(wz%m!=0) hs=n-wz%m+1;
		else hs=1;
	}else{
		if(wz%m!=0) hs=wz%m;
		else hs=n;
	}
	cout<<ls<<" "<<hs;
	return 0;
}
