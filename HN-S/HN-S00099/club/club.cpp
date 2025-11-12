#include<bits/stdc++.h>
using namespace std;
int t,n,m,xh[100005],cnt1,cnt2,cnt3,ans,m1,m2,m3;
int a1[50000],b1[50000],c1[50000];
int give1(int a[],int j){
	int maxn=0;
	while(j--){
		for(int i=0;i<n;i++){
			if(a[maxn]<a[i]){
				maxn=i;
			}
		}
		a1[cnt1]=maxn;
		cnt1++;
		maxn=0;
		a[maxn]=0;
	}	
}
int give2(int a[],int j){
	int maxn=0;
	while(j--){
		for(int i=0;i<n;i++){
			if(a[maxn]<a[i]){
				maxn=i;
			}
		}
		b1[cnt2]=maxn;
		cnt2++;
		maxn=0;
		a[maxn]=0;
	}	
}
int give3(int a[],int j){
	int maxn=0;
	while(j--){
		for(int i=0;i<n;i++){
			if(a[maxn]<a[i]){
				maxn=i;
			}
		}
		c1[cnt3]=maxn;
		cnt3++;
		maxn=0;
		a[maxn]=0;
	}	
}
int a[100005],b[100005],c[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>a[i];
		give1(a,m);
		give2(b,m);
		give3(c,m);
		for(int i=1;i<=cnt1;i++){
			xh[a1[i]]++;
		}
		for(int i=1;i<=cnt2;i++){
			xh[b1[i]]++;
		}
		for(int i=1;i<=cnt3;i++){
			xh[c1[i]]++;
		}
		for(int i=0;i<n;i++){
				int gg=max(max(a[a1[i]],b[b1[i]]),c[c1[i]]);
				ans+=gg;
		} 
		cout<<ans;
	}
	
	return 0;
} //六百六十六，动态规划不会写啊，布尔咋第一题就考动规啊，出题的诗人？那这我还玩屁啊，先跳了兄弟们。呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜呜 （写到了最后一刻还有50%没写完，直接就爽了） 
