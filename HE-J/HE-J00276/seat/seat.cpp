#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n*m],h=0;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>=a[1]) h++;
	}
	if(h%n!=0){
	cout<<(h/n)+1<<" ";
    }else{
    	cout<<h/n<<" ";
	}
	if(h%n!=0){
		if((h/n+1)%2==0)
		{
			cout<<n-(h%n)+1;
		}
		else{
			cout<<h%n;
		}
    }else{
    	if((h/n)%2==0)
		{
			cout<<1;
		}
		else{
			cout<<n;
		}
	}
	return 0;
}
