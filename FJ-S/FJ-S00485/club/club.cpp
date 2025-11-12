#include<bits/stdc++.h>
using namespace std;int a[100100][10],b[100100],c[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;int x;long long ans=0;
		int a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x=max(a[i][1],max(a[i][2],a[i][3]));
			if(x==a[i][1]){
				b[i]=1;a1++;
			}else if(x==a[i][2]){
				b[i]=2;a2++;
			}else{
				b[i]=3;a3++;
			}ans+=x;
		}int a4;
		if(a1>n/2){
			a4=1;
		}
		if(a2>n/2){
			a4=2;
		}
		if(a3>n/2){
			a4=3;
		}x=0;
		for(int i=1;i<=n;i++){
			if(b[i]==a4){
				x++;
				c[x]=a[i][a4]-(a[i][1]+a[i][2]+a[i][3]-a[i][a4]-min(a[i][1],min(a[i][2],a[i][3])));
			}
		}
		sort(c+1,c+x+1);
		for(int i=1;i<=x-n/2;i++){
			ans-=c[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}