#include<bits/stdc++.h> 
#define MAXN 50010
#define max(a,b) (((a)>(b))? (a):(b))
#define max3(a,b,c) max(max(a,b),c)
using namespace std;
struct x{
	int a[5];
	int m[3];
	bool operator <(x b){
		return b.a[4]<a[4];
	}
};
x a[MAXN];
void solve(){
	int n;
	char have3=0,have2=0;
	int ans=0;
	cin >> n;
	int ls[3]={n>>1,n>>1,n>>1};
	for (int i=0;i<n;i++){
		cin >> a[i].a[0] >> a[i].a[1] >> a[i].a[2];
		if (a[i].a[2]) have3=1;
		if (a[i].a[1]) have2=1;
		
		a[i].a[3]=max3(a[i].a[0],a[i].a[1],a[i].a[2]);
		ans+=a[i].a[3];
		a[i].a[0]=a[i].a[3]-a[i].a[0];
		a[i].a[1]=a[i].a[3]-a[i].a[1];
		a[i].a[2]=a[i].a[3]-a[i].a[2];
		a[i].a[4]=a[i].a[0]+a[i].a[1]+a[i].a[2]-max3(a[i].a[0],a[i].a[1],a[i].a[2]);
		for (int j=0;j<3;j++){
			if (a[i].a[j]==0) a[i].m[0]=j;
			else if (a[i].a[j]==a[i].a[4]) a[i].m[1]=j;
			else a[i].m[2]=j;
		}
	}
	sort(a,a+n);
	
	for (int i=0;i<n;i++){/*
		for (int j=0;j<5;j++)printf("%d ",a[i].a[j]);
		printf("\n");
		for (int j=0;j<3;j++)printf("%d ",a[i].m[j]);
		printf("\n");
		for (int j=0;j<3;j++)printf("%d ",ls[j]);
		printf("%d\n",ans);*/
		if (ls[a[i].m[0]]>0){
			ls[a[i].m[0]]--;
		} else if (ls[a[i].m[1]]>0){
			ls[a[i].m[1]]--;
			ans-=a[i].a[a[i].m[1]];
		} else {
			ls[a[i].m[2]]--;
			ans-=a[i].a[a[i].m[2]];
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
// 什么也不会的杂鱼爆炸了 

