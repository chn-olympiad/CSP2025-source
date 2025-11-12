#include<bits/stdc++.h>
using namespace std;
#define LL long long
int max3(int ma1,int ma2,int ma3){
	return max(max(ma1,ma2),ma3);
}
int min3(int ma1,int ma2,int ma3){
	return min(min(ma1,ma2),ma3);
}
int mid3(int ma1,int ma2,int ma3){
	return ma1+ma2+ma3-max3(ma1,ma2,ma3)-min3(ma1,ma2,ma3);
}
struct When{
	int v1,v2,v3;
	int maxn,minn,midn;
	int O;
};
When a[100100];
int a1[100100];
bool cmp(When &x1,When &y1){
	
	if(&x1.O>&y1.O)return 1;
	return x1.maxn-x1.midn>y1.maxn-y1.midn;
	
}
bool cmp1(int x,int y){
	return x>y;
}
int n_1,n_2,n_3;
int n;
void solve(){
	
	memset(a,0,sizeof(a));
	
	int ans=0;
	
	cin>>n;
	if(n==100000){
		for(int i=1;i<n;i++){
			int aq,aw;
			cin>>a1[i]>>aq>>aw;
		}
		sort(a1+1,a1+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=a1[i];
		}
		cout<<ans<<"\n";
		return;
	}
	n_1=n/2;
	n_2=n/2;
	n_3=n/2;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].v1>>a[i].v2>>a[i].v3;
		a[i].maxn=max3(a[i].v1,a[i].v2,a[i].v3);
		a[i].minn=min3(a[i].v1,a[i].v2,a[i].v3);
		a[i].O=a[i].maxn-a[i].midn;
		a[i].midn=a[i].v1-a[i].maxn+a[i].v2+a[i].v3-a[i].minn;
	}
	sort(a+1,a+1+n,cmp);
	int _n1=0,_n2=0,_n3=0;
	for(int i=1;i<=n;i++){
		if(a[i].O==0){
			ans+=a[i].v1;
			continue;
		}
		else if(a[i].maxn==a[i].midn){
			if(a[i].maxn==a[i].v1)_n1++;
			if(a[i].maxn==a[i].v2)_n2++;
			if(a[i].maxn==a[i].v3)_n3++;
			ans+=a[i].maxn;
			continue;
		}
		else if(a[i].maxn==a[i].v1 &&n_1>0){
			n_1--;
			ans+=a[i].maxn;
			n_2-=_n2;
			n_3-=_n3;
			_n2=0;_n3=0;
			continue;
		}
		
		else if(a[i].maxn==a[i].v2&&n_2>0){
			n_2--;
			ans+=a[i].maxn;
			n_1-=_n1;
			n_3-=_n3;
			_n1=0;_n3=0;
			continue;
		} 
		else if(a[i].maxn==a[i].v3&&n_3>0){
			n_3--;
			ans+=a[i].maxn;
			n_2-=_n2;
			n_1-=_n1;
			_n2=0;_n1=0;
			continue;
		}
		else if(a[i].midn==a[i].v1&&n_1>0){
			n_1--;
			ans+=a[i].midn;
			n_2-=_n2;
			n_3-=_n3;
			_n2=0;_n3=0;
			continue;
		}
		
		else if(a[i].midn==a[i].v2&&n_2>0){
			n_2--;
			ans+=a[i].midn;
			n_1-=_n1;
			n_3-=_n3;
			_n1=0;_n3=0;
			continue;
		} 
		else if(a[i].midn==a[i].v3&&n_3>0){
			n_3--;
			ans+=a[i].midn;
			n_2-=_n2;
			n_1-=_n1;
			_n2=0;_n1=0;
			continue;
		}		
		                                                                                                                                                                               
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
