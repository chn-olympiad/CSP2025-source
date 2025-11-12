#include<bits/stdc++.h>
using namespace std;
int n,m;
int an;
int a[105];
int cnt=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int u=n*m;
//	cout<<u<<"\n";
	for(int i=1;i<=u;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}
	int y=cnt/n;
	if(cnt%n!=0){
		y++;
		
		int o=cnt%n;
		if(y%2==0){
			an=n-o+1;
		}
		else an=o;
	}
	else if(cnt%n==0){
		if(y%2==0)
		an=1;
		if(y%2==1){
			an=n;
		}
	}
//	cout<<cnt<<"\n";
	cout<<y<<" "<<an;
	return 0; 
 } 