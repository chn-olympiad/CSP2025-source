#include<bits/stdc++.h>
using namespace std;
int t;
int a[100010][3];
int b[100010];
int c[100010];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		} 
		int flag1,flag2;
		for(int i=1;i<=n;i++){
			flag1+=a[i][2];
			flag2+=a[i][3];
		}
		int flag=flag1+flag2;
		for(int i=1;i<=n;i++){
			b[i]=a[i][1];
		}
		sort(b+1,b+n+1);
		if(flag==0){
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
		}
		cout<<ans<<"\n";
		ans=0;
		flag=0;
		flag1=0;
		flag2=0;
		for(int i=1;i<=n;i++){
			b[i]=0;
			for(int j=1;j<=3;j++){
				a[i][j]=0;
			}
		}
	}
	return 0;
}
