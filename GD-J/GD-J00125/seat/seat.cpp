#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=105;

int n,m,x,pm;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			pm=i;
			break;
		}
	}
	
	if(pm<=n){
		cout<<1<<' '<<pm;
		return 0;
	}
	
	if(pm%n==0){
		cout<<pm/n<<' ';
		
		if(pm/n%2==0)cout<<1<<' ';
		else cout<<n<<' ';
	}else{
		cout<<pm/n+1<<' ';
		
		if((pm/n+1)%2==0)cout<<n-(pm-pm/n*n)+1;
		else cout<<pm-pm/n*n;
	}
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
