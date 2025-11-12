#include <bits/stdc++.h>
using namespace std;
int a[105];
int z[15][15];
int sum(int A,int B){
	return A>B;
}
int main(){
	int n,m,x=1,u=0,e=0,s;
	cin>>n>>m;
	for(int i=1;i<=m*n;j++){
		cin>>a[j];
	}
	s=a[1];
	sort(a+1,a+m*n+1,sum);
	for(int i=1;i<=n;i++){
		z[x][i]==a[j];
		j++;
		if(s==z[x][i]){
			cout<<x<<" "<<i<<endl;
		}
		if(i==n){
			x+=1;
			
	    	if(s==z[x][i]){
		      cout<<z[x][i]<<endl;
		    }
	    }
			for(int i=n;i>=0;i++){
				z[x][i]=a[j];
			    if(i==1){
			    	if(x>m){
		               break;
		            }
				}
			}
			if(x>m){
			   break;
			}
	}
		    
}
