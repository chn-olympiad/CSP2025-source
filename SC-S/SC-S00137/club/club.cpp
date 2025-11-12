#include<bits/stdc++.h> 
using namespace std;
int a[100009][5],n,t,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	cin>>t;
	while(t--){
	    int a1=0,b1=0,c1=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			int ma=-99,k;
			for(int j=1;j<=3;j++){
				if(ma<a[i][j]){
					k=j;
					ma=a[i][j];
				}
			}
			c+=ma;
			if(k==1){
				a1++;
			}else if(k==2){
				b1++;
			}else{
				c1++;
			}
		}
		cout<<c;
	}
}