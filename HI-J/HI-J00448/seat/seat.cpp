#include <bits/stdc++.h>
using namespace std;
int a[1001][1001]={};
int cnt[1001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int t=1,ans=1,r,o=1,x,y;
	cin >>n>>m;
	for(int i=1; i<=n*m ; i++){
		cin >>cnt[i];
		if(i==1){
			r=cnt[i];
		}
	}
	for(int i=1 ; i<=n*m ; i++){
		if(o%2!=0){
			for(int j=1 ; j<=n ; j++){
				if(cnt[ans]<cnt[ans+1]){
					int b=cnt[ans];
					cnt[ans]=cnt[ans+1];
					cnt[ans+1]=b; 
				}
			}
		}
		if(o%2==0){
			for(int j=n ; j>=n ; j--){
				if(cnt[ans]<cnt[ans+1]){
					int b=cnt[ans];
					cnt[ans]=cnt[ans+1];
					cnt[ans+1]=b;
				} 
			}
		}
		cout <<cnt[ans]<<endl;
		ans++;
		if(i%n==1){
			o++;
		}
		
	}
	
	for(int i=1 ; i<=n*m ; i++){
		if(cnt[i]==r){
			x=(n*m)/n;
			y=(n*m)%n;
			if((x*n+y)%2==0){
				cout <<(i-1)/n+1<<" "<<n;
				return 0;
			}
			if((x*n+y)%2!=0){
				cout <<(i-1)/n+1<<" "<<y;
				return 0;
			}
		}
	}
}
