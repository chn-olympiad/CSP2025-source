#include<bits/stdc++.h>
using namespace std;
struct node{
	int s1,s2,s3;
};
int t;
int n;
node a[100005];
int d[100005];
vector <int> e[5];
long long s;
int c1,c2,c3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int b1=1,maxn=-1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		c1=0;
		c2=0;
		c3=0;
		s=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",&a[j].s1,&a[j].s2,&a[j].s3);
		}
		for(int j=1;j<=n;j++){
			b1=1;
			maxn=a[j].s1;
			d[j]=a[j].s1;
			if(maxn<a[j].s2){
				b1=2;
				d[j]=a[j].s2;
				if(maxn<a[j].s3){
					b1=3;
					d[j]=a[j].s3;
					c3++;
					e[b1][c3]=j;
				}
				else{
					c2++;
					e[b1][c2]=j;
				}
			}
			else{
				if(maxn<a[j].s3){
					b1=3;
					d[j]=a[j].s3;
					c3++;
					e[b1][c3]=j;
				}
				else{
					c1++;
					e[b1][c1]=j;
				}
			}
			e[b1][0]++;
		}
		for(int j=1;j<=n;j++){
			s=s+d[j];
		}
		printf("%lld",s);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}