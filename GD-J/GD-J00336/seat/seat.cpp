#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int xiao=a[0];
	for(int j=0;j<n*m;j++)
	{
		for(int i=0;i<n*m;i++)
		{
			if(a[i+1]>a[i])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	//for(int i=0;i<n*m;i++)
	//{
	//	cout<<a[i]<<' ';
	//}
	int xiaoxiao=0;
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==xiao)
		{
			xiaoxiao=i+1;
		}
	}
	//cout<<xiaoxiao;
	if(xiaoxiao%n!=0)
	{
		cout<<(xiaoxiao/n)+1<<' ';
		if(((xiaoxiao/n)+1)%2!=0)
		{
			cout<<n-(xiaoxiao%n)+1;//using namespace std;int  
		}
	}
}
/*¡÷¨Œ¡ð¡ó¡õ¡î?????¨ˆ¨‡¨†¨…¨…¨„¨ƒ¨„¨‚?????¡ì??¡ò¡è????¦Â¦Å¦Æ¦Ï¦Í©Ë©Ë©Ë©Ë©Í©Î©Ë©Å¨v¨v¨u¨u¨v©e 
*/
