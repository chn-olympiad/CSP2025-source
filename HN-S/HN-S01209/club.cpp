#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
long long c[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t; cin>>t;
	while(t--){
		long long aj=1,bj=1,cj=1,cnt=0;
		long long n; cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				cnt+=a[i];
				aj++;
			}else if(b[i]>c[i]&&b[i]>a[i]){
				cnt+=b[i];
				bj++;
			}else{
				cnt+=c[i];
				cj++;
			}
	 	}
	 	bool p[100005]={0};
	 	long long aj1=aj;
	 	long long bj1=bj;
	 	long long cj1=cj;
		while(aj-1>n/2){
			long long mn=INT_MAX,jl;
			for(long long i=1;i<aj1;i++){
				long long cs=min(a[i]-b[i],a[i]-c[i]);
				if(cs<mn&&p[i]==0){
					mn=cs;
					jl=i;
				}
			}
			p[jl]=1;
			aj--;
			cnt-=mn;
		}
		while(bj-1>n/2){
			long long mn=INT_MAX,jl;
			for(long long i=1;i<bj1;i++){
				long long cs=min(b[i]-a[i],b[i]-c[i]);
				if(cs<mn&&p[i]==0){
					mn=cs;
					jl=i;
				}
			}
			p[jl]=1;
			bj--;
			cnt-=mn;
		}
		while(cj-1>n/2){
			long long mn=INT_MAX,jl;
			for(long long i=1;i<cj1;i++){
				long long cs=min(c[i]-b[i],c[i]-a[i]);
				if(cs<mn&&p[i]==0){
					mn=cs;
					jl=i;
				}
			}
			p[jl]=1;
			cj--;
			cnt-=mn;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
