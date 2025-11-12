#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],ch;
bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	ch=a[1];
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++)cout<<a[i]; 
	for(int i=1;i<=n*m;i++)
	  if(a[i]==ch)
	  {
	  	ch=i;
	  	break;
	  }
	if(ch<=n)cout<<1<<' '<<ch;
	else if(((ch+n-1)/n)%2!=0)
	{
		cout<<(ch+n-1)/n<<" "<<ch%n;
	}  
	else
	{
		cout<<(ch+n-1)/n<<" "<<n-(ch%n)+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
