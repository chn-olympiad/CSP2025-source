#include<bits/stdc++.h>
using namespace std;
bool deng(const int & a,const int & b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int zong=n*m;
	int a[105]={0};
	for(int i=1;i<=zong;i++)
	{
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+1+zong,deng);
	int ss=0;
	for(int i=1;i<=zong;i++)
	{
		if(a[i]==a1)
		{
			ss=i;
			break;
		}
	}
	int lie=ss/n;
	int hang=ss%n;
	if(hang==0){
		if(lie%2==1){
			cout<<lie<<' '<<n;
			return 0;
		}
		else{
			cout<<lie<<' '<<1;
			return 0;
		}
	}
	else{
		lie++;
		if(lie%2==1){
			cout<<lie<<' '<<hang;
			return 0;
		}
		else{
			cout<<lie<<' '<<n+1-hang;
			return 0;
		}
	}
}

