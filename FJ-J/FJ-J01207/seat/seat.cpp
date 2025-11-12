#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[101],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			a[(i-1)*m+j]=x;
		}
	}
	R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==R){
			p=n*m-i+1;
			break;
		}
	}
	int l=1,r=0,sum=0;
	while(sum!=p){
		if(sum+m>=p){
			if(l%2==0){
				for(int i=1;i<=n;i++){
					if(sum+i==p){
						sum+=i;
						r=n-i+1;
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(sum+i==p){
						sum+=i;
						r=i;
						break;
					}
				}
			}
		}
		else{
			l++;
			sum+=m;
		}
	}
	cout<<l<<' '<<r<<"\n";
	return 0;
}
