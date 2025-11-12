#include<bits/stdc++.h>
using namespace std;
long long m,n,c,r,b;
long long a[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b=a[1];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){			
			if(a[i]==b){
				if(j>n||i>m){ 
					r=i+1;
					c=j+1;	
				}else{
					c=j;
					r=i;
				}	
			}else{
				i++;
				j++;
			}
		}
	}
	
	cout<<c<<' '<<r;
	return 0; 
} 
