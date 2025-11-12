#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,T,ans;
struct node{
	int t;
	bool iu;
}a[N],b[N],c[N];
bool cmp(node a,node b){
	return a.t>b.t;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].t>>b[i].t>>c[i].t;
			a[i].iu=b[i].iu=c[i].iu=0;
		}sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1,j=1,k=1;i+j+k-3<n;){	
		    int dt;	
			if(i>n/2||j>n/2||k>n/2){
				if(i>n/2)dt=max(b[j].t,c[k].t);
				else if(j>n/2)dt=max(a[i].t,c[k].t);
				else if(k>n/2)dt=max(a[i].t,b[j].t);
				else if(k>n/2&&j>n/2)dt=a[i].t;
				else if(i>n/2&&j>n/2)dt=c[k].t;
				else if(i>n/2&&k>n/2)dt=b[j].t;		
			}else dt=max(a[i].t,max(b[j].t,c[k].t));		  
			if(i<=n/2&&dt==a[i].t&&!a[i].iu){
				ans+=a[i++].t;
				a[i-1].iu=1;
			}
			else if(j<=n/2&&dt==b[j].t&&!b[j].iu){
				ans+=b[j++].t;
				b[j-1].iu=1;
			}
			else if(k<=n/2&&dt==c[k].t&&!c[k].iu){
				ans+=c[k++].t;
				c[k-1].iu=1;
			}
		}cout<<ans<<endl;
	}return 0;
}
