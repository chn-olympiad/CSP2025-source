#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m,num=0;
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	while(l<r){
		int mid=l+r>>1;
		if(a[mid]>k)l=mid+1;
		else r=mid;
	}
	num=l;
	if(num<=n){
		cout<<1<<" "<<n;
		return 0;
	}
	int lie=num/n;
	if(num%n!=0)lie++;
	int cha=num%n;
	if(lie%2==0){
		cout<<lie<<" "<<n-cha+1;
	}
	else{
		cout<<lie<<" "<<cha;
	}
	return 0;
}
/*
2 2
98 99 100 97 
*/

