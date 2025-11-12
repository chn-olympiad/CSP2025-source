#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ad[105],j,sx,sy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];	
	}j=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		ad[i]=a[n*m+1-i];
		if(ad[i]==j){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==0){
				cout<<n-((i-1)%n+1)+1;
			}else{
				cout<<(i-1)%n+1;
			}
		}
	}
	return 0;	
}
