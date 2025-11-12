#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
struct Node{
	int one;
	int two;
	int three;
}z[10010];
int main(){
    freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>z[i].one>>z[i].two>>z[i].three;
	    }
        for(int i=n;i>=1;i--){
			if(z[i].one>=z[i].two&&z[i].one>=z[i].three){
				if(a<n/2){
					a++;
					ans+=z[i].one;
				}else{
					if(z[i].two>=z[i].three){
						b++;
						ans+=z[i].two;
					}else{
						c++;
						ans+=z[i].three;
					}
				}
			}else if(z[i].two>=z[i].three&&z[i].two>=z[i].one){
				if(b<n/2){
					b++;
					ans+=z[i].two;
				}else{
					if(z[i].one>=z[i].three){
						a++;
						ans+=z[i].one;
					}else{
						c++;
						ans+=z[i].three;
					}
				}
			}else{
				if(c<n/2){
					c++;
					ans+=z[i].three;
				}else{
					if(z[i].one>=z[i].two){
						a++;
						ans+=z[i].one;
					}else{
						b++;
						ans+=z[i].two;
					}
				}
			}
		}
        for(int i=1;i<=n;i++){
			if(z[i].one>=z[i].two&&z[i].one>=z[i].three){
				if(a<n/2){
					a++;
					sum+=z[i].one;
				}else{
					if(z[i].two>=z[i].three){
						b++;
						sum+=z[i].two;
					}else{
						c++;
						sum+=z[i].three;
					}
				}
			}else if(z[i].two>=z[i].three&&z[i].two>=z[i].one){
				if(b<n/2){
					b++;
					sum+=z[i].two;
				}else{
					if(z[i].one>=z[i].three){
						a++;
						sum+=z[i].one;
					}else{
						c++;
						sum+=z[i].three;
					}
				}
			}else{
				if(c<n/2){
					c++;
					sum+=z[i].three;
				}else{
					if(z[i].one>=z[i].two){
						a++;
						sum+=z[i].one;
					}else{
						b++;
						sum+=z[i].two;
					}
				}
			}
		}
		if(ans>=sum){
			cout<<ans<<endl;
		}else{
			cout<<sum<<endl;
		}
	}
	return 0;
}
