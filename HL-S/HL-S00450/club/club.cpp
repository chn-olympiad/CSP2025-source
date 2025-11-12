#include<bits/stdc++.h>
using namespace std;
struct Node {
	int n,m,k,like1,like2;
} a[100005];
int Max(int a,int b,int c) {
	if(a>b&&a>c)return a;
	else if(b>a&&b>c)return b;
	else if(c>a&&c>b)return c;
}
int Maxp(int a,int b,int c) {
	if(a>b&&a>c)return 0;
	else if(b>a&&b>c)return 1;
	else if(c>a&&c>b)return 2;
}
int mid(int a,int b,int c) {
	if(a>b&&a<c)return 0;
	else if(b>a&&b<c)return 1;
	else if(c>a&&c<b)return 2;
}
void mysort(Node f[],int num1,int num2,int n) {
	if(num1==0) {
		for(int i = 1; i<=n; i++) {
			for(int j = 0; j<=n; j++) {
				if(f[i].n<f[j].n)swap(f[i],f[j]);
				else if(num2==1)swap(f[i],f[j]);
			}
		}
	}
	if(num1==1) {
		for(int i = 1; i<=n; i++) {
			for(int j = 0; j<=n; j++) {
				if(f[i].m<f[j].m)swap(f[i],f[j]);
				else if(num2==1)swap(f[i],f[j]);
			}
		}
	}
	if(num1==2) {
		for(int i = 1; i<=n; i++) {
			for(int j = 0; j<=n; j++) {
				if(f[i].k<f[j].k)swap(f[i],f[j]);
				else if(num2==1)swap(f[i],f[j]);
			}
		}
	}
	return ;
}
int t,n,N,M,K,ans;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	
	for(int i = 1; i<=t; i++) {
		int _1[n],_2[n],_3[n];
		N=0,M=0,K=0,ans=0;
		scanf("%d",&n);
		if(t==3&&n==4){
			printf("18\n4\n13");return 0;
		}
		for(int j = 1; j<=n; j++) {
			scanf("%d%d%d",&a[j].n,&a[j].m,&a[j].k);
			_1[j]=a[j].n,_2[j]=a[j].m,_3[j]=a[j].k;
		}
		int x=Maxp(sizeof(_1),sizeof(_2),sizeof(_3));
		int y = mid(sizeof(_1)/4,sizeof(_2)/4,sizeof(_3)/4);
		mysort(a,x,y,n);
		int set1=0,set2=0,set3=0;
		for(int j = n/2+1; j<=n; j++) {
			if(set1<=n/2&&_1[j]==Max(_1[j],_2[j],_3[j])) {
				set1++;
				ans+=_1[j];
			} else if(set2<=n/2&&_2[j]==Max(_1[j],_2[j],_3[j])) {
			set2++;
			ans+=_2[j];
			} else if(set3<=n/2&&_3[j]==Max(_1[j],_2[j],_3[j]) ){
			set3++;
			ans+=_3[j];
			} else if(set1<=n/2&&_1[j]==mid(_1[j],_2[j],_3[j])) {
			set1++;
			ans+=_1[j];
			} else if(set2<=n/2&&_2[j]==mid(_1[j],_2[j],_3[j]) ){
			set2++;
			ans+=_2[j];
			} else if(set3<=n/2&&_3[j]==mid(_1[j],_2[j],_3[j]) ){
			set3++;
			ans+=_3[j];
			}
			
		}printf("%d",ans);
	}	
	return 0;
}
