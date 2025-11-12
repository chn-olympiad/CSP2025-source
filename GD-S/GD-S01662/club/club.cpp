#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct tt{
	ll i,v,li;
}a1[101000],a2[101000],a3[101000],b[10];
bool cmp(tt a,tt b){
	return a.v>b.v;
}
ll sum[10],sum1[10],n,i,t,ans,T;
bool vis[101000];
ll ff(){
	sum[1]=sum[2]=sum[3]=1;
	sum1[1]=sum1[2]=sum1[3]=0;
	t=0;
	while(t<n){
		b[1]=a1[sum[1]],b[2]=a2[sum[2]],b[3]=a3[sum[3]];
		sort(b+1,b+4,cmp);
		for(i=1;i<=3;i++){
			if(vis[b[i].i]){
				sum[b[i].li]++;
			}
			if(!vis[b[i].i]&&sum1[b[i].li]+1<=n/2){
				ans+=b[i].v;
				vis[b[i].i]=1;
				sum[b[i].li]++;//di ji ge
				sum1[b[i].li]++; 
				t++;
				break;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		if(n==2){
			cin>>a1[1].v>>a1[2].v>>a1[3].v>>a2[1].v>>a2[2].v>>a2[3].v;
			a1[1].li=a2[1].li=1;
			a1[2].li=a2[2].li=2;
			a1[3].li=a2[3].li=3;
			sort(a1+1,a1+4,cmp);
			sort(a2+1,a2+4,cmp);
			if(a1[1].li!=a2[1].li) ans=a1[1].v+a2[1].v;
			else{
				if(a1[1].v>a2[1].v){
					if(a1[2].v+a2[1].v>a1[1].v) ans=a1[2].v+a2[1].v;
					else ans=a1[1].v;
				}else{
					if(a1[1].v+a2[2].v>a2[1].v) ans=a1[1].v+a2[2].v;
					else ans=a2[1].v;
				}
			}
			cout<<ans;
			continue;
		}
		for(i=1;i<=n;i++){
			cin>>a1[i].v>>a2[i].v>>a3[i].v;
			a1[i].i=a2[i].i=a3[i].i=i;
			a1[i].li=1,a2[i].li=2,a3[i].li=3;
			vis[i]=0;
		}
		sort(a1+1,a1+1+n,cmp);
		sort(a2+1,a2+1+n,cmp);
		sort(a3+1,a3+1+n,cmp);
		//l1l2l3
		ff();
		cout<<ans<<"\n";
	}
	return 0; 
} 
