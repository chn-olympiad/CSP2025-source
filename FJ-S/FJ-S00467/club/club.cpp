#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][4],Na[100005];
int max_of_2,max_of_3;
int Q,K;
long long ans;
int A,B,C;
void Au(){
	for(int i=1;i<=n;i++){
		if(Q==n/2) ans+=a[i][2];
		else if(K==n/2) ans+=a[i][1];
		else{
			int k=max(a[i][1],a[i][2]);	
			if(a[i][1]==k) Q++;
			else K++;
			ans+=k;
		}
	}
	cout<<ans;
}
void Ag(){
	for(int i=1;i<=n;i++){
		if(A<n/2&&B<n/2&&C<n/2){
			int D=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=D;
			if(a[i][1]==D) A++;
			else if(a[i][2]==D) B++;
			else if(a[i][3]==D) C++;	
		}
		else if(A==n/2){
			ans+=max(a[i][2],a[i][3]);
		}
		else if(B==n/2){
			ans+=max(a[i][1],a[i][3]);
		}
		else if(C==n/2){
			ans+=max(a[i][1],a[i][2]);
		}
	}
	cout<<ans;	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==1) Na[i]=a[i][j];
				if(j==2) max_of_2=max(max_of_2,a[i][j]);
				if(j==3) max_of_3=max(max_of_3,a[i][j]);
			}
		}
		if(n==2){
			cout<<max(max(max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),a[1][2]+a[2][1]),a[1][2]+a[2][3]),a[1][3]+a[2][2]),a[1][3]+a[2][1]);
		}
		else if(n==4){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int d=1;d<=3;d++){
							if((i==j&&j==k)||(i==j&&j==d)||(i==k&&k==d)||(j==k&&k==d)){
								ans=max(ans,(long long)a[1][i]+a[2][j]+a[3][k]+a[4][d]);
							}
						}
					}
				}
			}
		}
		else if(n==200){
			if(max_of_3==0){
				Au();
			}
			else{
				Ag();
			}
		}
		else if(n>200){
			if(max_of_2==0&&max_of_3==0){
				sort(Na+1,Na+n+1);
				for(int i=1;i<=n;i++){
					ans+=Na[i];
				}
				cout<<ans;
			}
			else if(max_of_3==0){
				Au();
			}
			else{
				Ag();
			}
		}
		else{
			Ag();
		}
	}
	return 0;
}