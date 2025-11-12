//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int hang,lie;
bool cmp(int w,int y)
{
	return w>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int l=a[1],k;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==l)
		{
			k=i;
		}
	}
	if(k%n!=0) lie=k/n+1;
	else lie=k/n;
	if(lie==1)
	{
		cout<<lie<<" "<<k;
		return 0;
	}
	if(lie%2==0)
	{
		hang=n-k%n+1;
	}
	else hang=k%n;
	if(hang==0) hang=n;
	cout<<lie<<" "<<hang;
	return 0;
} 
