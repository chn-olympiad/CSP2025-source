#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],b[100005],ans;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int l1=-1,l2,l3=-1,r1=-1,r2,r3=-1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
					if(i==1&&a[i][j]>l1){
						l1=a[i][j];
						l2=j;
					}
					else if(i==2&&a[i][j]>r1){
						r1=a[i][j];
						r2=j;
					}
				}
			}
			if(l2!=r2){
				cout<<l1+r1;
			}
			else{
				for(int i=1;i<=n;i++){
					for(int j=1;j<=3;j++){
						if(i==1&&a[i][j]>l3&&l2!=j){
							l3=a[i][j];
						}
						else if(i==2&&a[i][j]>r3&&r2!=j){
							r3=a[i][j];
						}
					}
				}
				if(l1+r3>l3+r1){
					cout<<l1+r3;
				}
				else{
					cout<<l3+r1;
				}
			}
			continue;
		}
		int p1=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				b[i]=a[i][1];
			}
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=b[i];
		}
		cout<<ans;
	}
	return 0;
}
