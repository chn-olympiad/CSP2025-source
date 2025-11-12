#include<bits/stdc++.h>
using namespace std;

int a[100005],n,c,m,b,k,p,l[100005];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i];
		l[i]=a[i];
		}
		for (int i=0;i<n*m;i++){
        	for(int j=1;j<n*m;j++){
        		if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
		for(int i=0;i<n*m;i++){
			//cout<<l[i];
			if(a[i]=l[1]){
				p=i;
			
			}
			c=p/n+1;
			k=p%m;
			cout<<c<<""<<k;
			
		}
		return 0;
		
}
	
	


