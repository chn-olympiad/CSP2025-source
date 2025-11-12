#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,kk,s=1,c=-1,r=-1;
	cin>>n>>m;
	kk=n*m;
	int a,R;
	cin>>R;
	for(int i=2;i<=kk;i++){
		cin>>a;
		if(a>R)s++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2){
			for(int j=1;j<=n;j++){
				s--;
				if(s==0){
					c=i,r=j;
					break;
				}
			}
		}
		else {
			for(int j=n;j>=1;j--){
				s--;
				if(s==0){
					c=i,r=j;
					break;
				}
			}
		}
		if(c>0&&r>0)break;
	}
	cout<<c<<' '<<r;
	return 0;
}
