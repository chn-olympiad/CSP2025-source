#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,l,r,sum;
int a[1010];
bool f;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	tot=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i]==tot)sum=i;
	}
	if(n==1)f=1;
	l=sum/n;
	if(sum%n!=0)l+=1; 
	r=sum-((l-1)*n);
	if(f){
		cout<<l<<" "<<1;
		return 0;
	}
	if(l&1)cout<<l<<" "<<r;
	else cout<<l<<" "<<m-r+1;
	return 0;
}

