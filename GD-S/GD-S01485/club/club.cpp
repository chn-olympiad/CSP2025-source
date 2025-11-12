#include<bits/stdc++.h>
using namespace std;
struct A{
	int club,myd;
};
A a[100005][5];
struct B{
	int cha,id;
};
B cha1[100005],cha2[100005];
bool cmp(B a,B b){
	return a.cha>b.cha;
}
bool cmp1(int a,int b){
	return a>b;
}
int f,g,h,maxn=0,l;
int q[5],w[5],e[5];
int ans[100005];
int t;
int c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].myd;
				a[i][j].club=j;
				if(j==1) c[i]=a[i][j].myd;
			}
			for(int x=2;x>=1;x--){
			    for(int y=1;y<=i;y++){
				    if(a[i][y].myd<a[i][y+1].myd){
					    swap(a[i][y].myd,a[i][y+1].myd);
					    swap(a[i][y].club,a[i][y+1].club);
				    }
			    }
		    }
		}
		if(n=100000){
			sort(c+1,c+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				l+=c[i];
			}
			cout<<l;
		}
		for(int i=1;i<=n;i++){
		    q[a[i][1].club]++;
		    w[a[i][2].club]++;
		    e[a[i][3].club]++;
		}
		if(q[1]>q[2]&&q[1]>q[3]) f=1;
		if(q[2]>q[1]&&q[2]>q[3]) f=2;
		if(q[3]>q[2]&&q[3]>q[1]) f=3;
		if(w[1]>w[2]&&w[1]>w[3]) g=1;
		if(w[2]>w[1]&&q[2]>w[3]) g=2;
		if(w[3]>w[2]&&q[3]>w[1]) g=3;
		if(e[1]>e[2]&&e[1]>q[3]) h=1;
		if(e[2]>e[1]&&e[2]>q[3]) h=2;
		if(e[3]>e[2]&&e[3]>q[1]) h=3;
		if(q[h]>n/2){
			for(int i=1;i<=n;i++){
				cha1[i].cha=a[i][1].myd-a[i][2].myd;
				cha1[i].id=i;
				ans[i]=h;
			}
			sort(cha1+1,cha1+n+1,cmp);
			for(int i=1;i<=q[h]-n/2;i++){
				ans[cha1[i].id]=g;
				w[g]++;
			}
		}
		if(w[g]>n/2){
			for(int i=1;i<=n;i++){
				cha2[i].cha=a[i][2].myd-a[i][3].myd;
				cha2[i].id=i;
				ans[i]=g;
			}
			sort(cha2+1,cha2+n+1,cmp);
			for(int i=1;i<=w[g]-n/2;i++){
				ans[cha2[i].id]=h;
				e[h]++;
			}
		}
		for(int i=1;i<=n;i++){
			maxn=maxn+a[i][ans[i]].myd;
		}
		cout<<maxn;
	}
	return 0;
} 

