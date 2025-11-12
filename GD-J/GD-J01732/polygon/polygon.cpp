#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s,num,mx;
int d(int k,int p){
	if(p==0){
		if(s>2*mx){
			num++;
			num=num%998244353;
		}
		return 0;	
	}
	for(int i=k;i<=n;i++){
		s+=a[i];
		if(p==1)mx=a[i];
		d(i+1,p-1);
		s-=a[i];
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		s=0,mx=0;
		d(1,i);
	}
	cout<<num;
	return 0;
}
