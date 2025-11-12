#include<iostream>
//#include<cmath>
#include<algorithm>
//#include<string>
#include<cstdio>
using namespace std;
int b[100005];
int a[100005];
int hang,lie,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	b[1]=s;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+1+n*m);
//	int s=b[n*m];//成绩
//	cout<<"成绩："<<s<<endl;
	for(int i=1;i<=n*m;i++)
	{
		a[i]=b[n*m-i+1];
//		cout<<a[i]<<" ";
		
		if(a[i]==s)
		{
//			cout<<endl;
//			cout<<"在第"<<i<<"个时截止"<<endl;
			lie=(i-1)/n+1;
			if(lie%2==1)hang=i-(lie-1)*n;
			else hang=n+1-(i-(lie-1)*n);
			
			cout<<lie<<" "<<hang;
			break;
		}
		
	}

	
	return 0;
}
//2 2 99 100 97 98
//3 3 94 95 96 97 98 99 100 93 9
