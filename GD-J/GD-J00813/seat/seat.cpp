#include<bits/stdc++.h>
using namespace std;
int n,m,dir,p,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum=n*m;
	for (int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int sp_grade=a[1];
	
	sort(a+1,a+sum+1,cmp);
	
	for (int i=1;i<=sum;i++){
		if (a[i]==sp_grade){
			dir=i;
			break;
		}
	}
	
	if (dir%n==0){
		cout<<n/dir<<" ";
		p=n/dir;
	}
	else{
		cout<<(dir/n)+1<<" ";
		p=(dir/n)+1;
	}
	
	if (p%2==0){
		cout<<n-(dir%n)+1<<endl;
	}
	else{
		cout<<(dir%n)<<endl;
	}
	return 0;
}
