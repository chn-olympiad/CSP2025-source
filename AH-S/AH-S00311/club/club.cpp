#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int id[N],s[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		int i1=0,i2=0,i3=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			int t=0;
			if(a[i]>=b[i])t=1;
			else t=2;
			if(t==1){
				if(a[i]>=c[i])t=1;
				else t=3;
			}
			else {
				if(b[i]>=c[i])t=2;
				else t=3;
			}
			ans+=max({a[i],b[i],c[i]});
			if(t==1)i1++,id[i]=1;
			else if(t==2)i2++,id[i]=2;
			else i3++,id[i]=3;
		}
		for(int x=1;x<=3;x++){
			int t=0;
			if(x==1)t=i1;
			if(x==2)t=i2;
			if(x==3)t=i3;
			if(t>n/2){
				int k=0;
				for(int i=1;i<=n;i++){
					if(id[i]==x){
						k++;
						if(x==1)s[k]=(a[i]-max(b[i],c[i]));
						if(x==2)s[k]=(b[i]-max(a[i],c[i]));
						if(x==3)s[k]=(c[i]-max(b[i],a[i]));
					}
				}
				sort(s+1,s+1+k);
				int j=1;
				while(t>n/2){
					ans-=s[j];
					j++;
					t--;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
