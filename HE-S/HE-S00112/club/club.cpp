#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
struct ch{
	int x;
	int g;
}f[N];
int T,a[N],n,b[N],c[N],num1[N],num2[N],cnt[10],fr[N],ans;
bool cmp(ch a,ch b){
	return a.g>b.g;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int ma=max(max(a[i],b[i]),c[i]);
			int ma2;
			if(ma==a[i]){
				ma2=max(b[i],c[i]);
				fr[i]=1;

			}
			if(ma==b[i]){
				ma2=max(a[i],c[i]);
				fr[i]=2;

			}
			if(ma==c[i]){
				fr[i]=3;
				ma2=max(a[i],b[i]);

			}
			num1[i]=ma,num2[i]=ma2;
			f[i].x=i,f[i].g=ma-ma2;
		}
		
		sort(f+1,f+n+1,cmp);
		//int cnt=0;
		for(int i=1;i<=n;i++){
			int ff=fr[f[i].x];
			if(cnt[ff]<n/2){
				ans+=num1[f[i].x];
				cnt[ff]++;
			}
			else {
				ans+=num2[f[i].x];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
