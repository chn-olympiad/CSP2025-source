#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
  	freopen("seat.out","w",stdout);
	int c=0,r=0,n,m,mycode,sum=1;
	cin>>n >> m;
	int a[n*m]={};
	cin >> mycode;
	for(int i=1;i<n*m;i++){
		cin >> a[i];
		if(a[i]>mycode) sum++;
	}
	if(sum<=n){
		c=1;
		r=sum;
		cout<<c<<" "<<r;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=2;i<=m;){		
		if(sum>n*(i-1) and sum <= n*i){
			if(i%2==0){	
				c=i;
				if(sum%n*i==0) r=1;
				else r=sum%n*i;
				cout<<c<<" "<<r;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}	
			else if(i%2==1){
				c=i;
				r=sum-n*(i-1);
				cout<<c<<" "<<r;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}	
		}
		i++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}