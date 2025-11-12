#include<bits/stdc++.h>
using namespace std;

int t,n;
struct node{
	int w[5],num;
	int mx1,mx2;
}a[100010];
int c[100010];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(a[i].w[j]>a[i].w[a[i].mx1]){
				a[i].mx2=a[i].mx1;
				a[i].mx1=j;
			}
			else if(a[i].w[j]>a[i].w[a[i].mx2]){
				a[i].mx2=j;
			}
		}
		
		c[i]=a[i].w[a[i].mx1]-a[i].w[a[i].mx2];
	}
	return ;
}

bool cmp(node x,node y){
	if(c[x.num]>c[y.num]){
		return true;
	}
	return false;
}

int main( ){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i].w[j]);
				a[i].num=i;a[i].mx1=0,a[i].mx2=0;
			}
		}
		init();
		sort(a+1,a+1+n,cmp);
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].mx1==1&&cnt1<n/2){
				ans+=a[i].w[a[i].mx1];
				cnt1++;continue;
			}
			if(a[i].mx1==2&&cnt2<n/2){
				ans+=a[i].w[a[i].mx1];
				cnt2++;continue;
			}
			if(a[i].mx1==3&&cnt3<n/2){
				ans+=a[i].w[a[i].mx1];
				cnt3++;continue;
			}
			
			if(a[i].mx1==1&&cnt1==n/2){
				ans+=a[i].w[a[i].mx2];
			}
			if(a[i].mx1==2&&cnt2==n/2){
				ans+=a[i].w[a[i].mx2];
			}
			if(a[i].mx1==3&&cnt3==n/2){
				ans+=a[i].w[a[i].mx2];
			}
			
			if(a[i].mx2==1){
				cnt1++;
			}
			if(a[i].mx2==2){
				cnt2++;
			}
			if(a[i].mx2==3){
				cnt3++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
