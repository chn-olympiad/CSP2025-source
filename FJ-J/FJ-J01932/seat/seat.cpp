#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10005],num=1;
int main(){
//	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
// 	freopen("seat1.in","r",stdin);
// 	freopen("seat1.ans","w",stdout);
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);
 	
 	cin>>n>>m;
 	cin>>a[1];
 	for(int i=2;i<=n*m;i++)
 	{
 		cin>>a[i];
 		if(a[i]>a[1])
 		{
 			num++;
		 }
	 }
//	 cout<<num;
	 if(num%n==0)
	 {
	 	if((num/n)%2==0)
	 	{
	 		cout<<num/n<<" "<<1;
	 		return 0;
		 }
		 else
		 {
//		 	cout<<"www";
		 	cout<<num/n<<" "<<n;
		 	return 0;
		 }
	 }
 	int x=num/n;
// 	cout<<num/n*n;
 	if(x%2==0)
 	{
 		cout<<x+1<<" "<<num-num/n*n;
	 }
 	else
 	{
 		cout<<x+1<<" "<<n-(num-num/n*n)+1;
	 }
 	return 0;
 }
