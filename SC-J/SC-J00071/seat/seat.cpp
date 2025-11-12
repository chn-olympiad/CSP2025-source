#include<bits/stdc++.h>
using namespace std;
int n,m,l,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	int a[100]={0};
	int b[100]={0};
	cin>>a[0];
	l=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	for(int i=1;i<=n*m;i++)
	{
		b[i]=a[n*m-i];
		if(b[i]==l)
		{
			k=i;
		}
	}
	if(k>n){
		if(k%n!=0){
			cout<<1+k/n<<' ';
			if((k/n+1)%2==0)
			{
				cout<<m-k%n+1;
			}
			else{
				cout<<k%n;
			}
		}
		else{
			cout<<m<<' '<<n/2;
		}
	}
	else{
		cout<<1<<' '<<k;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}