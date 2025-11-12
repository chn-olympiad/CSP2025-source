#include<bits/stdc++.h>
using namespace std;
long long dp,w[101010],n,t,a[4][100000],s[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	for(int i=1;i<=4;i++)
	s[i]=0;
	dp=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=n;i++){
				if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
					if(s[1]<=n/2){
						dp=a[1][i]+dp;
						s[1]++;
					
					}
					else{
				if(a[2][i]>=a[3][i]){
			if(s[2]<=n/2){
          dp=a[2][i]+dp;
          s[2]++;
		}		
					}
					else{
						if(s[3]<n/2){
          dp=a[3][i]+dp;
          s[3]++;
		}	
					}
				}
				}
				else{
			if(a[2][i]>=a[3][i]&&a[2][i]>=a[1][i]){
			if(s[2]<=n/2){
          dp=a[2][i]+dp;
          s[2]++;
		}
		else{
				if(a[1][i]>=a[3][i]){
			if(s[1]<=n/2){
          dp=a[1][i]+dp;
          s[1]++;
		}		
					}
					else{
						if(s[3]<=n/2){
          dp=a[3][i]+dp;
          s[3]++;
		}	
					}
				}
		}		else {
			if(a[3][i]>=a[2][i]&&a[3][i]>=a[1][i]){
		if(s[3]<=n/2){
						dp=a[3][i]+dp;
						s[3]++;
			}
			else{
				if(a[2][i]>=a[1][i]){
			if(s[1]<=n/2){
          dp=a[1][i]+dp;
          s[1]++;
		}		
					}
					else{
						if(s[2]<=n/2){
          dp=a[2][i]+dp;
          s[2]++;
		}	
					}
				}
		}	
			}
				}
			
			
			
cout<<dp<<endl;
}
    
	return 0;
}
}
