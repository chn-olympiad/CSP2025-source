#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
    int a[n*m+10];
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+n*m+1);
	int cnt=1;
	while(a[cnt]!=q){
		cnt++;
	}
	while(cnt){
		for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				cnt--;
				if(cnt==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2!=0){
			for(int p=n;p>=1;p--){
				cnt--;
				if(cnt==0){
					cout<<i<<" "<<p;
					return 0;
				}
				
				
			
		    }
		}
		
	   }
	
		
	}
	
	
	
	return 0;
} 
