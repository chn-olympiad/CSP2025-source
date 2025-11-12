#include<bits/stdc++.h>
using namespace std;
long long ans,A[100010],B[100010],C[100010],a,b,c;
int t,n,numa,numb,numc;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n,ans=0,numa=0,numb=0,numc=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c)A[++numa]=-min(a-b,a-c);
			else if(b>=a&&b>=c)B[++numb]=-min(b-a,b-c);
			else C[++numc]=-min(c-a,c-b);
			ans+=max(a,max(b,c));
		}
		sort(A+1,A+numa+1);
		sort(B+1,B+numb+1);
		sort(C+1,C+numc+1);
		for(int i=numa;i>n/2;i--)ans+=A[i];
		for(int i=numb;i>n/2;i--)ans+=B[i];
		for(int i=numc;i>n/2;i--)ans+=C[i];
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
