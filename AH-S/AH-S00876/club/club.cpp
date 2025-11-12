#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,ls1,ls2,ls3,a[20010],b[20010],c[20010],sla,slb;//a[i]:cong b tiao dao a de dai jia
bool cmp(long long a,long long b){
	return a<b;
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		sla=0;
		slb=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ls1>>ls2>>ls3;
			if(ls1>ls2){
				sla++;
				b[sla]=ls1-ls2;
				ans+=ls1;
			}
			else{
				slb++;
				a[slb]=ls2-ls1;
				ans+=ls2;
			}
		}		
		if(sla>n/2){
			long long gz=sla-n/2;
			sort(b+1,b+sla+1,cmp);
			for(int i=1;i<=gz;i++){
				ans-=b[i];
			}
		}
		else{
			long long gz=slb-n/2;
			sort(a+1,a+slb+1,cmp);
			for(int i=1;i<=gz;i++){
				ans-=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
