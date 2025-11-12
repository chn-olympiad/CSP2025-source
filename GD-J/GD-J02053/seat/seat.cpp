#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,b,c,d;
	cin>>n>>m;
	int a[n*m];
	cin>>a[0];
	b=a[0];
	for(i=1;i<n*m;i++){
		cin>> a[i];
	}
	sort(a,a+(n*m));
	j=1;
	for(i=(n*m)-1;i>=0;i--){
		if(a[i]==b){
			break;
		}
		j++;
	}
	c=j/n;
	d=j%n;
	if(c%2==1){
		if(d==0){
			cout<< c<< " "<< n;
		}else{
			cout<< c+1<< " "<< n-d+1;
		}
	}else{
		if(d==0){
			cout<< c<< " "<< 1;
		}else{
			cout<< c+1<< " "<< d;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
