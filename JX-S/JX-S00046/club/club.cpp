#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,a[N][4],cnt1,cnt3;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++){
			if(!a[i][1])
				cnt1++;
			if(!a[i][3])
				cnt3++;
		}
		if(n==2){
			int x=max(a[2][2],a[2][3])+a[1][1],y=max(a[2][1],a[2][3])+a[1][2],z=max(a[2][1],a[2][2])+a[1][3];
			cout<<max(x,max(y,z))<<endl;
			continue;
		}
		if(cnt1==n&&cnt3==n){
			int ce=n/2,b[N],cnt=1,sum=0;
			for(int i=1;i<=n;i++)
				b[cnt++]=a[i][2];
			sort(b+1,b+cnt+1);
			for(int i=1;i<=ce;i++)
				sum+=b[i];
			cout<<sum<<endl;
			continue;
		}
	}
	return 0;
}
