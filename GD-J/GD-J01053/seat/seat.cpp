#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000],b;
bool camp(int a,int b)
{
	return a>b;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{ 
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,camp);
	int num;
	for(int i=1;i<=n*m;i++)
		if(a[i] == b)
			num = i;
	//cout<<num<<endl;
	int y=(num-1)/n+1;
	if(y % 2 == 1)
		cout<<y<<' '<<(num-1)%n+1;
	else
		cout<<y<<' '<<n - (num-1)%n;
	
	return 0;
} 
