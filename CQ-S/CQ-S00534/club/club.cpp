#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005],b[100005],c[100005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		a[0]=0;
		b[0]=0;
		c[0]=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				ans+=x;
				a[0]++;
				a[a[0]]=x-max(y,z);
			}else if(y>=x&&y>=z){
				ans+=y;
				b[0]++;
				b[b[0]]=y-max(x,z);
			}else{
				ans+=z;
				c[0]++;
				c[c[0]]=z-max(y,x);
			}
		}
		if(a[0]>n/2){
			sort(a+1,a+1+a[0]);
			for(int i=1;i<=a[0]-n/2;i++){
				ans-=a[i];
			}
		}
		if(b[0]>n/2){
			sort(b+1,b+1+b[0]);
			for(int i=1;i<=b[0]-n/2;i++){
				ans-=b[i];
			}
		}
		if(c[0]>n/2){
			sort(c+1,c+1+c[0]);
			for(int i=1;i<=c[0]-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

