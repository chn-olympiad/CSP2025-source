#include<iostream>
using namespace std;
int n,m,a[105],tmp[105],cnt=0,r;
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			tmp[a[i]]=2;
		}else{
			tmp[a[i]]=1;
		}
		
	}
	for(int i=100;i>=1;i--){
		if(tmp[i]==1){
			a[++cnt]=i;
		}else if(tmp[i]==2){
			r=cnt+1;
			a[++cnt]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				r--;
				if(r==0){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else if(i%2==0){
			for(int j=m;j>=1;j--){
				r--;
				if(r==0){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
	}
	return 0;
}
