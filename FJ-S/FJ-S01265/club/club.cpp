#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int s,d;
}a[100005][5],jue[5][100005],a1[100005][5];
bool cmp1(node n1,node n2){
	return n1.s>n2.s;
}
bool cmp2(node n1,node n2){
	return n1.s<n2.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long ans=0;
		scanf("%d",&n);
		int dd[5]={0},mm=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].s,&a[i][2].s,&a[i][3].s);
			a1[i][1].s=a[i][1].s;
			a1[i][2].s=a[i][2].s;
			a1[i][3].s=a[i][3].s;
			a[i][1].d=1;
			a[i][2].d=2;
			a[i][3].d=3;
			sort(a[i]+1,a[i]+4,cmp1);
			dd[a[i][1].d]++;
			ans+=a[i][1].s;
			jue[1][i].s=a[i][a[i][1].d].s-a[i][1].s;
			jue[2][i].s=a[i][a[i][1].d].s-a[i][2].s;
			jue[3][i].s=a[i][a[i][1].d].s-a[i][3].s;
			jue[1][i].d=i;
			jue[2][i].d=i;
			jue[3][i].d=i;
		}
		int f=1;
		for(int i=1;i<=3;i++){
			if(dd[i]>mm)f=0;
		}
		if(f){
			printf("%lld\n",ans);
			continue;
		}
		sort(jue[1]+1,jue[1]+1+n,cmp2);
		sort(jue[2]+1,jue[2]+1+n,cmp2);
		sort(jue[3]+1,jue[3]+1+n,cmp2);
		int li=1;
		for(int j=1;j<3;j++){
			li=1;
		while(dd[1]>mm){
			int x;
			if(jue[2][li].s<jue[3][li].s){
				x=a1[jue[2][li].d][2].s;
				dd[2]++;
			}else{
				x=a1[jue[3][li].d][3].s;
				dd[3]++;
			}
			ans=ans-a1[jue[1][li].d][1].s+x;
			li++;
			dd[1]--;
		}
		li=1;
		while(dd[2]>mm){
			int x;
			if(jue[1][li].s<jue[3][li].s){
				x=a[jue[1][li].d][1].s;
				dd[1]++;
			}else{
				x=a[jue[3][li].d][3].s;
				dd[3]++;
			}
			ans=ans-a1[jue[2][li].d][2].s+x;
			li++;
			dd[2]--;
		}
		li=1;
		while(dd[3]>mm){
			int x;
			if(jue[2][li].s<jue[1][li].s){
				x=a[jue[2][li].d][2].s;
				dd[2]++;
			}else{
				x=a[jue[1][li].d][1].s;
				dd[1]++;
			}
			ans=ans-a1[jue[3][li].d][3].s+x;
			li++;
			dd[3]--;
		}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
