#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){ return  a>b;}
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	
	int c;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			c=i;
			break;
		}
	}
	
	int x=(c+n-1)/n,y=c%n;
	if(!y)y=n;
	if(x%2==0) y=n-y+1;
	
	cout<<x<<" "<<y;
	
	return 0;
}