#include<bits/stdc++.h>
using namespace std;
int a[100005][4],n,t,cnt1,cnt2,cnt3,d[100005];
long long ans;
int v1[100005];
int v2[100005];
int v3[100005];
int c[100005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		for(int i=1;i<=100000;i++){
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
			d[i]=0;
			v1[i]=0;
			v2[i]=0;
			v3[i]=0;
			c[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				d[i]=a[i][1]-max(a[i][2],a[i][3]);
				cnt1++;
				v1[cnt1]=i;
			}
			else if(a[i][2]>=a[i][3]){
				d[i]=a[i][2]-max(a[i][1],a[i][3]);
				cnt2++;
				v2[cnt2]=i;
			}
			else{
				d[i]=a[i][3]-max(a[i][2],a[i][1]);
				cnt3++;
				v3[cnt3]=i;
			}
		}
		for(int i=1;i<=cnt1;i++) ans+=a[v1[i]][1];
		for(int i=1;i<=cnt2;i++) ans+=a[v2[i]][2];
		for(int i=1;i<=cnt3;i++) ans+=a[v3[i]][3];
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;i++){
				c[i]=d[v1[i]];
			}
			sort(c+1,c+cnt1+1,cmp);
			for(int i=1;i<=cnt1-n/2;i++)
				ans-=c[i];
		}
		if(cnt2>n/2){
			for(int i=1;i<=cnt2;i++){
				c[i]=d[v2[i]];
			}
			sort(c+1,c+cnt2+1,cmp);
			for(int i=1;i<=cnt2-n/2;i++)
				ans-=c[i];
		}
		if(cnt3>n/2){
			for(int i=1;i<=cnt3;i++){
				c[i]=d[v3[i]];
			}
			sort(c+1,c+cnt3+1,cmp);
			for(int i=1;i<=cnt3-n/2;i++)
				ans-=c[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
