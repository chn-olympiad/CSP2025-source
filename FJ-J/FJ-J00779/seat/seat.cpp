#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n,m,w,ans,c,r;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
		if(i == 1){
			w = a[1];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i = 1;i<=n*m;i++){
		if(a[i] == w){
			ans = i;
			break;
		}
	}
	ans = n*m-ans+1;
	if(ans<=n){
		c = 1;
	}
	else{
		if(ans%n==0){
			c = ans/n;
		}
		else{
			c = ans/n+1;
		}
		
	}
	
	if(ans<=n){
		r = ans;
	}
	else{
		if(c%2 == 1){
			r = ans-((c-1)*n);
		}
		if(c%2 == 0){
			r = n-(ans-(c-1)*n)+1;
		}
			
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
