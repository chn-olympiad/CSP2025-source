#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
	int t1,t2,t3;
}a[N];
bool cmp(node x,node y){
	if(x.t1-x.t2!=y.t1-y.t2) return x.t1-x.t2<y.t1-y.t2;
	return x.t2-x.t3<y.t2-y.t3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int s1=0,s2=0,s3=0,s=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].b>=a[i].c){a[i].t1=a[i].a;a[i].t2=a[i].b;a[i].t3=a[i].c;s1++;}
			else if(a[i].a>=a[i].c&&a[i].c>=a[i].b){a[i].t1=a[i].a;a[i].t2=a[i].c;a[i].t3=a[i].b;s1++;}
			else if(a[i].b>=a[i].a&&a[i].a>=a[i].c){a[i].t1=a[i].b;a[i].t2=a[i].a;a[i].t3=a[i].c;s2++;}
			else if(a[i].b>=a[i].c&&a[i].c>=a[i].a){a[i].t1=a[i].b;a[i].t2=a[i].c;a[i].t3=a[i].a;s2++;}
			else if(a[i].c>=a[i].b&&a[i].b>=a[i].a){a[i].t1=a[i].c;a[i].t2=a[i].b;a[i].t3=a[i].a;s3++;}
			else if(a[i].c>=a[i].a&&a[i].a>=a[i].b){a[i].t1=a[i].c;a[i].t2=a[i].a;a[i].t3=a[i].b;s3++;}
			s+=a[i].t1;
		}
		if(s1<=n/2&&s2<=n/2&&s3<=n/2){
			printf("%d\n",s);
			continue;
		}
		//最大的向第2大的移动，第2大的向第3大的移动
		sort(a+1,a+n+1,cmp);
		//if((max(max(s1,s2),s3)>=(n+1)/2&&n%2==1)){
		//	puts("No");//continue;
		//}
		if(s1>n/2){
			int cha=s1-n/2;
			for(int i=1;i<=n&&cha;i++){
				if(a[i].t1==a[i].a&&a[i].t2==a[i].b&&s2+1<=n/2){
					s1--,s2++;
					s=s-a[i].a+a[i].b;
					cha--;
					//printf("%d:a->b,%d",i,cha);
				}
				else if(a[i].t1==a[i].a&&a[i].t2==a[i].c){
					s1--,s3++;
					s=s-a[i].a+a[i].c;
					cha--;
				}
			}
			if(cha){
				for(int i=1;i<=n&&cha;i++){
					if(a[i].t1==a[i].a&&a[i].t3==a[i].b){
						s1--,s2++;
						s=s-a[i].a+a[i].b;
						cha--;
						//printf("%d:a->b,%d",i,cha);
					}
					else if(a[i].t1==a[i].a&&a[i].t3==a[i].c){
						s1--,s3++;
						s=s-a[i].a+a[i].c;
						cha--;
					}
				}
			}
		}
		if(s2>n/2){
			int cha=s2-n/2;
			for(int i=1;i<=n&&cha;i++){
				if(a[i].t1==a[i].b&&a[i].t2==a[i].a&&s1+1<=n/2){
					s2--,s1++;
					s=s-a[i].b+a[i].a;
					cha--;
				}
				else if(a[i].t1==a[i].b&&a[i].t2==a[i].c){
					s2--,s3++;
					s=s-a[i].b+a[i].c;
					cha--;
				}
			}
			if(cha){
				for(int i=1;i<=n&&cha;i++){
					if(a[i].t1==a[i].b&&a[i].t3==a[i].a){
						s2--,s1++;
						s=s-a[i].b+a[i].a;
						cha--;
					}
					else if(a[i].t1==a[i].b&&a[i].t3==a[i].c){
						s2--,s3++;
						s=s-a[i].b+a[i].c;
						cha--;
					}
				}
			}
		}
		if(s3>n/2){
			int cha=s3-n/2;
			for(int i=1;i<=n&&cha;i++){
				if(a[i].t1==a[i].c&&a[i].t2==a[i].a&&s1+1<=n/2){
					s3--,s1++;
					s=s-a[i].c+a[i].a;
					cha--;
				}
				else if(a[i].t1==a[i].c&&a[i].t2==a[i].b){
					s3--,s2++;
					s=s-a[i].c+a[i].b;
					cha--;
				}
			}
			if(cha){
				for(int i=1;i<=n&&cha;i++){
					if(a[i].t1==a[i].c&&a[i].t3==a[i].a){
						s3--,s1++;
						s=s-a[i].c+a[i].a;
						cha--;
					}
					else if(a[i].t1==a[i].c&&a[i].t3==a[i].b){
						s3--,s2++;
						s=s-a[i].c+a[i].b;
						cha--;
					}
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
