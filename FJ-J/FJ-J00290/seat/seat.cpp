#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int seat[105][105];
int a[1005];
int grade;
int paiming;
int x,y,k;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>seat[i][j];
			a[k]=seat[i][j];
			k++;
			if(i==1&&j==1)
			grade=seat[i][j];
		}
	}
	sort(a,a+k);
	reverse(a,a+k);
	for(int i=0;i<k;i++){
		if(a[i]==grade){
			paiming=i+1;
			break;
		}
	}
	if(paiming%n!=0)
	y=paiming/n+1;
	else
	y=paiming/n;
	if(y%2==0){
		if(paiming%n!=0)
		x=n-paiming%n+1;
		else
		x=1;
	}
	else{
		if(paiming%n!=0)
		x=paiming%n;
		else
		x=n;
	}
	cout<<y<<" "<<x;
	return 0;
}
