#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][3],b[N],v[3],c[N][3],ans,t,n,num;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		num=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]==a[i][3] && a[i][2]==0){
				num++;
			}
		}
		if(num==n){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				num=max(a[i][j],num);
			}
			for(int j=1;j<=3;j++){
				if(num==a[i][j]){
					v[i]+=1;
					c[i][j]=a[i][j];
				}
				else{
					c[i][j]=-1;
				}
			}
			ans+=num;
		}
		for(int i=1;i<=3;i++){
			if(v[i]>n/2){
				for(int j=1;j<=n;j++){
					b[j]=c[j][i];
				}
				sort(b+1,b+n+1);
				for(int j=1;j<=n;j++){
					if(v[i]<=n/2){
						continue;
					}
					if(b[j]!=-1){
						ans-=b[j];
						v[i]--;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
