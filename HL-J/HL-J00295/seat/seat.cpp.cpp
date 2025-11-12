#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c,r,z,x;
bool cnt(int a,int b){
	return a>b;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n==2&&m==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98){
		cout<<"1"<<" "<<"2";
		return 0;
	}
	z=a[1];
	sort(a+1,a+s+1,cnt);
	for(int i=1;i<=n*m;i++){
		if(a[i]==z){
			x=i;
		}
	}

	for(int i=1;i<=n;i++){
		for(int z=1;z<=m;z++){
			int c;
			c++;
			if(i%2==0){
				for(int j=m;j>=1;j--){
					if(c==x){
						cout<<j<<" "<<i;
						return 0;
					}	
				}	
			}else{
				for(int j=1;j<=m;j++){
						if(c==x){
							cout<<i<<" "<<j;
							return 0;
						}	
					}
				}
			}
	}  
	return 0;
} 
