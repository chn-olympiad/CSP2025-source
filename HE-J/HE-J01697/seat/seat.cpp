#include<bits/stdc++.h>
using namespace std;
int main(){
	
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int r=1;
	int a[105]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	int c=0;
	sort(a,a+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			c=i;
			break;
		}
	}
	if(c<=n){
		cout<<r<<" "<<c;
	}else{
			r+=c/n;
			if(c==1){
				c=n;
			}else if(c==n){
				c=1;
			}else if(c==n-1){
				c-=1;
			}else if(c==n/2+1){
				c=c;
			}else{
				c+=1;
			}
			cout<<r<<" "<<c;
		
	}

	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
} 
