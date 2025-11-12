#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a,b[n*m]={},c,l=0,r=n*m-1;
	for(int i=0;i<n*m;i++)cin>>b[i];
	c=b[0];
	sort(b,b+n*m,cmp);
	while(l<=r){
		int mid=(l+r)>>1;
		if(b[mid]==c){
			a=mid;
			break;}
		if(b[mid]>c)l=mid+1;
		else if(b[mid]<c)r=mid-1;}
	a++;
	if(!(a%n))cout<<a/n<<' '<<((a/n)%2?n:1);
	else{
		int h=a/n+(a%n==0?0:1);
		cout<<h<<' '<<(h%2?a-n*(h-1):m+1-(a-n*(h-1)));}
	return 0;}
