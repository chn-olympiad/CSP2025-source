#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
int b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int rs=m*n;
	
	for(int i=1;i<=rs;i++){
		cin>>a[i];
	}
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	int R=a[1];
	sort(a+1,a+rs+1,cmp);
	int pm;
	for(int i=1;i<=rs;i++){
		if(a[i]==R)
		pm=i;
	}
	int x=pm,y=pm;
	if((pm/n+1)%2==1){
		cout<<x/n+1<<" "<<y%n;
	}
	else{
		cout<<x/n+1<<" "<<n-y%n+1;
	}
	return 0;
}
