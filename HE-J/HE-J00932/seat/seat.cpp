#include<bits/stdc++.h> 
using namespace std;
long long n,m,a1,flag;
long long a[20000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
    	cin>>a[i];
    	if(i==1) a1=a[i];
    	//cout<<a1<<endl;
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
    {
    	if(a[i]==a1) 
		{
			flag=n*m-i+1;
			break;
		}	
	}
	if(flag%n==0)
	{
		if((flag/n)%2==0) cout<<flag/n<<" "<<1<<endl;
		else cout<<flag/n<<" "<<n<<endl;
	}
    else
    {
    	if((flag/n+1)%2==0) cout<<(flag/n)+1<<" "<<n-(flag%n)+1<<endl;
		else cout<<(flag/n)+1<<" "<<flag%n<<endl;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
