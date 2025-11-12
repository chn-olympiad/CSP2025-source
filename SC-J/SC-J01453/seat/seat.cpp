#include<bits/stdc++.h>
using namespace std;

int a[100+10];

bool cmp(int a,int b){
	if(a<b) return 0;
	return 1;
}

int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	
	int n,m;          
	cin>>n>>m;
	
	for(int i=1; i<=n*m; i++) cin>>a[i];
	
	int tmp;
	tmp=a[1];
	
	sort(a+1,a+n*m+1,cmp);
	int p;
	for(int i=1; i<=n*m; i++){
		if(a[i]==tmp){
			p=i;
			break;
		}
	}
	

	
	int x=p/n;
	int y=p%n;
	
	if(x%2==0){
		if(y==0){
			cout<<x<<" "<<1;
		}else{
			cout<<x+1<<" "<<y;
		}
	}else{
		if(y==0){
			cout<<x<<" "<<n; 
		}else{
			cout<<x+1<<" "<<n-y+1;
		}
	}

	return 0;
}
