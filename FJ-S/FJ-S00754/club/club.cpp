#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,t,a,b,c,x,y,z,sum=0,stua[N],stub[N],stuc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		x=y=z=0;
		long long ans=0;
		cin>>n;
		int half=(n/2);
		int tot1=0,tot2=0,tot3=0;
		for(long long j=1;j<=n;j++){
			cin>>a>>b>>c;
			if(a>b&&a>c){
				tot1+=a;
				x++;
				stua[j]+=a-max(b,c);
			}
			if(b>a&&b>c){
				tot2+=b;
				y++;
				stub[j]+=b-max(a,c);
			}
			if(c>a&&c>b){
				tot3+=c;
				z++;
				stuc[j]+=c-max(a,b);
			}
		}
		for(long long j=1;j<=half;j++){
			sum=0;
			if(x>half){
				sort(stua,stua+n+1);
				sum=x-half;
				for(long long m=1;m<=sum;m++)
					tot1-=stua[m];
			}
			sum=0;
			if(y>half){
				sort(stub,stub+1+n);
				sum=y-half;
				for(long long m=1;m<=sum;m++)
					tot2-=stub[m];
			}
			sum=0;
			if(z>half){
				sort(stuc,stuc+1+n);
				sum=z-half;
				for(long long m=1;m<=sum;m++)
					tot3-=stuc[m];
			}
		}
		ans=tot1+tot2+tot3;
		cout<<ans<<endl;
	}
	return 0;
}
