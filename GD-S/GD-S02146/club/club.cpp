#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,a,b,c,k;
int tmp[200007],h,ans;
int x[200007],y[200007],z[200007],r[200007],mx[200007],mn[200007],g[200007];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);//1.5e6Input!!!
			mx[i]=max(max(x[i],y[i]),z[i]);
			mn[i]=min(min(x[i],y[i]),z[i]);
			r[i]=2*mx[i]+mn[i]-(x[i]+y[i]+z[i]);
			ans+=mx[i];
			if(mx[i]==x[i]){
				a++;
				g[i]=1;
			}
			else if(mx[i]==y[i]){
				b++;
				g[i]=2;
			}
			else{
				c++;
				g[i]=3;
			}
			//cout<<r[i]<<endl;
		}
		//cout<<a<<' '<<b<<' '<<c<<endl;
		if(a>n/2){
			h=0;
			for(int i=1;i<=n;i++){
				if(g[i]==1){
					h++;
					tmp[h]=r[i];
				}
			}
			sort(tmp+1,tmp+h+1);
			for(int i=1;i<=a-n/2;i++) ans-=tmp[i];
		}
		if(b>n/2){
			h=0;
			for(int i=1;i<=n;i++){
				if(g[i]==2){
					h++;
					tmp[h]=r[i];
				}
			}
			sort(tmp+1,tmp+h+1);
			for(int i=1;i<=b-n/2;i++) ans-=tmp[i];
		}
		if(c>n/2){
			h=0;
			for(int i=1;i<=n;i++){
				if(g[i]==3){
					h++;
					tmp[h]=r[i];
				}
			}
			sort(tmp+1,tmp+h+1);
			for(int i=1;i<=c-n/2;i++) ans-=tmp[i];
		}
		cout<<ans<<endl;
		ans=0;
		a=b=c=0;
	}
	return 0;
} 
