#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[101]={0},r,t;
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
		cin>>a[i];
	r=a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<m*n;j++)
		{
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==r)
			t=i+1;}
	if(t%n==0){
		cout<<t/n<<' ';
		if(t/n%2==0)
			cout<<1;
		else
			cout<<n;}
	else{
		cout<<t/n+1<<' ';
		if((t/n+1)%2==0)
			cout<<n+1-t%2;
		else
			cout<<t%2;}
	fclose(stdin);
	fclose(stdout);
}
