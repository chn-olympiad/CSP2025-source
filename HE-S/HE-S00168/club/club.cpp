#include<bits/stdc++.h>
using namespace std;
struct bumen{
	int b1;
	int b2;
	int b3;
};
int s[100005][4];
int ans[100005];
int b[10];
bumen a[100005];
int t;
int n;
int cnt=0;
int cnt2=1;
bool cmp1(int x,int y){
	if(x>y){
		return true;
	}
	else return false;
}
bool cmp2(bumen x,bumen y){
	if(x.b1>y.b1){
		return true;
	}
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			cin>>a[1].b1>>a[1].b2>>a[1].b3;
			cin>>a[2].b1>>a[2].b2>>a[2].b3;
			b[1]=a[1].b1+a[2].b2;
			b[2]=a[1].b1+a[2].b3;
			b[3]=a[1].b2+a[2].b1;
			b[4]=a[1].b2+a[2].b3;
			b[5]=a[1].b3+a[2].b1;
			b[6]=a[1].b3+a[2].b2;
			sort(b+1,b+1+6,cmp1);
			cout<<b[1];
		}
		if(n==4){
					for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					for(int l=1;l<=3;l++){
						if((i!=k&&i!=l&&(j!=k||j!=l))||(i!=j&&i!=k&&(j!=k||j!=l))||(i!=j&&i!=l&&(k!=j||k!=l))||(j!=i&&j!=k&&(i!=k||i!=l))||(k!=l&&k!=j&&(i!=j||i!=l))||(k!=l&&k!=i&&(i!=j||i!=l))||(k!=i&&k!=j&&(i!=j||i!=l))||(j!=k&&j!=l&&(i!=k||i!=l))||(j!=i&&j!=l&&(i!=k||i!=l))){
							ans[cnt2]=s[1][i]+s[2][j]+s[3][k]+s[4][l];
							cnt2++;
						}
					}
				}
			}
		}
		sort(ans+1,ans+1+cnt2,cmp1);
		cout<<ans[1];
		for(int i=1;i<=cnt2;i++){
			ans[i]=0;
		}
		cnt2=0;
	}
		else{for(int i=1;i<=n;i++){
			cin>>a[i].b1>>a[i].b2>>a[i].b3;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			cnt+=a[i].b1;
		}
		cout<<cnt;
		cnt=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
