#include<bits/stdc++.h>
using namespace std;

int n,m,a[200],c,r,R;

int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;//h l
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	
	sort(a+1,a+n*m+1);
	
	int j=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==R){
			if(j%n==0){
				c=j/n;
			}else{
				c=j/n+1;
			}
			
			if(c%2==0){
				if(j%n==0){
					r=1;
				}else{
					r=n-(j%n)+1;
				}
			}else{
				if(j%n==0){
					r=n;
				}else{
					r=j%n;
				}
			}
			
			break;
		}
		j++;
	}
	cout<<c<<" "<<r;//l h
	
	return 0;
}
