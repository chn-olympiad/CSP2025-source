#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int num[1000];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>num[i];
	int a1=num[1];
	sort(num+1,num+1+n*m,cmp);
	int pm=0;
	for(int i=1;i<=n*m;i++)if(num[i]==a1)pm=i;
//	cout<<pm<<endl;
	if(((pm-1)/n+1)%2==1){
		cout<<(pm-1)/n+1<<' '<<(pm-1)%n+1;
	}
	else {
		cout<<(pm-1)/n+1<<' '<<n-pm%n+1;
	}
	return 0;
}

