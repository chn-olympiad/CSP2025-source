#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,x=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a1=i;
			x=i;
		}
	}
	for(int i=1;i<=a1;i++){
		
		if(x<=n){
			if(i%2==1){
				cout<<i<<" "<<x;
			}
			else{
				cout<<i<<" "<<n+1-x;
			
			}
			break;
		}
		x-=n;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
