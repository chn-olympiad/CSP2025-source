#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005];
int c,b,x;
int m,q,p;
int s;
int main(){
	
	
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	
	if(t==1){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b = max(a[i],b);
			
		}
		
		x == b;
		if(x == a[1]){
			
			m++;
		}
		if(x == a[2]){
			q++;
		}
		if(x == a[3]){
		
		
		
			p++;
			
		}
		if(m>n/2){
			b = max(a[1],b);
			if(b==x){
				b = max(a[2],b);
				x ==b;
			
			
			
			}
			else{
				b == max(a[3],b);
				x == b;
			}
			x == b;

	}
	}
	if(t!=1){
	for(int j =1;j<=t;j++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b = max(a[i],b);
			
		}
		x == b;
		if(x == a[1]){
			
			m++;
		}
		if(x == a[2]){
			q++;
		}
		if(x == a[3]){
			p++;
			
		}
		if(m>n/2){
			b = max(a[1],b);
			if(b==x){
				b = max(a[2],b);
				x ==b;
			}
			else{
				b == max(a[3],b);
				x == b;
			}
			x == b;

	}
	}
		
		
		
	}	
		
		
		s+=b;
	
	
	
	
		cout<<s+b-1;
	return 0;
}
