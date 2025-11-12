#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int mm=a[0],js=1;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>mm) js++;
	}	
	if(js%n==0 ){
		int jj=js/n;
		if(jj%2==0){
			cout<<jj<<" "<<1;
		}else{
			cout<<jj<<" "<<n;
		}
	}else{
		int jj=js/n+1;
		if(jj%2==0){
			cout<<jj<<" "<<n-js%n+1;
		}else{
			cout<<jj<<" "<<js%n;
		}
	} 
	
	return 0;
}
