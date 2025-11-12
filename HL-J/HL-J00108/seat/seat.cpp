#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,b=1,sum=0;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=0;i<sum;i++){
		cin>>a[i];
	}
	for(int i=1;i<=sum;i++){
		if(a[0]<a[i]||c%2==0){
			b-=1;
			if(b==1){
				c+=1;
			}
				
		}
		else if(a[0]<a[i]||c%2==1){
			if(b==m){
				c+=1;
			}
			else{
				b+=1;
			}	
		}
		else if(a[0]>=a[i]){
			return 0;
		}
	}
	cout<<c<<" "<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
