#include<bits/stdc++.h>
using namespace std;
const int N=1e5+91;
int a[N][4];
int b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n+2;i++){
			b[i]=1;
		}
		int ni=n/2;
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		b[1]=0;
		while(b[n+1]==1){
			sum=0;
			b[1]+=1;
			int ca=0,cb=0,cc=0;
			for(int i=1;i<=n;i++){
				if(b[i]==4){
					b[i]=1;
					b[i+1]++;
				}
				if(b[i]==1){
					ca++;
				}
				if(b[i]==2){
					cb++;
				}
				if(b[i]==3){
					cc++;
				}
				sum+=a[i][b[i]];
			}
			if(ca<=ni&&cb<=ni&&cc<=ni){
				ans=max(ans,sum);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
