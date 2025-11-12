#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int s[100005];
int pp,j;
int c,r;
bool ww,ll;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==i){
			ww=1;
		}
		else{
			ww=0;
			break;
		}
		if(a[i]==n*m-i+1){
			ll=1;
		}
		else{
			ll=0;
			break;
		}
			
	}
	if(ww==1){
		c=m;
		r=n;
	}
	else if(ll==1){
		c=1;
		r=1;
		
	}
	else{
		pp=a[1];
		sort(s+1,s+1+n,greater<int>());
		for(int i=1;i<=n*m;i++){
			if(s[i]==pp){
				j=i;
				break;
			}
		}
		if(j%n==0){
			if((j/n)%2==1){
				c=j/n;
				r=n;
			}
			else{
				c=j/n;
				r=1;
			}
		}
		else{
			c=ceil(j/n)+1;
			if(c%2==0){
				r=n;
			}
			else{
				r=j%n;
			}
		}
	}
	
    cout<<c<<" "<<r;

	return 0;
	
	fclose(stdin);
	fclose(stdout);
} 
