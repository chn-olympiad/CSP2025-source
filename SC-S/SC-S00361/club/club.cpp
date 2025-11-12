#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N],b[N],c[N],m,p,q,a1[5],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	++t;
	while(--t){
		a1[1]=0;
		a1[2]=0;
		a1[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		ans=0;
		while(0==0){
			m=-1;
			for(int i=1;i<=n;++i){
				if(a[i]>m&&a1[1]<n/2){
					m=a[i];
					p=i;
					q=1;
				}if(b[i]>m&&a1[2]<n/2){
					m=b[i];
					p=i;
					q=2;
				}if(c[i]>m&&a1[3]<n/2){
					m=c[i];
					p=i;
					q=3;
				}
			}
			if(m==-1)break;
			ans+=m;
			a[p]=-1;
			b[p]=-1;
			c[p]=-1;
			a1[q]++;
		}
		cout<<ans<<endl;
	}
}