#include<bits/stdc++.h>
using namespace std;
int T;
bool A=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T!=0){
		int n,ans=0;
		int a1[100005],a2[100005],a3[100005];
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if (a2[i]!=0||a3[i]!=0)A=false;
		}
		if (A==true){
			sort(a1+1,a1+n+1);
			int y=n/2,q=0;
			while(y){
				ans+=a1[n-q];
				y--,q++;
			}
			cout<<ans<<endl;
			T--;
			continue;
		}
		if (n==2){
			int d1=a1[1]+a2[2];
			int d2=a1[1]+a3[2];
			ans=max(d1,d2);
			d1=a2[1]+a3[2];
			d2=a2[1]+a1[2];
			ans=max(ans,max(d1,d2));
			d1=a3[1]+a2[2];
			d2=a3[1]+a1[2];
			ans=max(ans,max(d1,d2));
			cout<<ans<<endl;
		}
		T--;
	}
	return 0;
} 
