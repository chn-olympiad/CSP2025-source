#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int s=n*m;
	int a[s];
	for(int i=0;i<s;i++)
	{
		cin >>a[i];
	}
	int xiaoR=a[0];
	sort(a,a+s);
	reverse(a,a+s);
	if(xiaoR==a[0]){
		cout<<"1 1";
		return 0;
	}
	int wei;
	for(int i=0;i<s;i++)
	{
		if(a[i]==xiaoR){
			wei=i+1;
			break;
		}
	}
	if(wei<=n){
		cout<<"1 "<<wei;
		return 0;
	}
	int l=(wei+n-1)/n;
	int h=l*n-wei;
	if(l%2==0){
		cout<<l<<" "<<h+1;
		return 0;
	}
	else {
		cout<<l<<" "<<n-h;
		return 0;
	}
	return 0;
}
