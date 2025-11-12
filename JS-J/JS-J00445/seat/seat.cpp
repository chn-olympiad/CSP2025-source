#include<bits/stdc++.h>
using namespace std;
const int N = 105;

bool cmp(int a,int b){
	return a>b;
}

int a[N];

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	int n,m,R = 0;
	cin>>n>>m;
	
	for(int i = 1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	
	for(int i = 0;i<m;i++){
		
		for(int j = 1;j<=n;j++){
			if(a[i*n+j] == R){
				cout<<i+1<<" "<<j;
				return 0;
			}
		}
		
		i++;
		
		for(int j = n;j>=1;j--){
			if(a[i*n+n-j+1] == R){
				cout<<i+1<<" "<<j;
				return 0;
			}
		}
		
	}
	
	return 0;
}
