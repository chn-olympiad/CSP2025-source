#include<bits/stdc++.h>
using namespace std;
struct node{
	int a, b, c;
}a[10005];
int t, n[205], sum, sum2;
bool cmp(node a,node b){
	return (a.a+a.b+a.c) > (b.a+b.b+b.c);
}
bool cmp1(node a,node b){
	return (a.a+a.b+a.c) <= (b.a+b.b+b.c);
}
int q1, q2, q3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		sum=0;sum2=0;
		q1=0;
		q2=0;
		q3=0;
		scanf("%d",n+i);
		for(int j=1;j<=n[i];j++){
			scanf("%d%d%d",&a[j].a,&a[j].b,&a[j].c);
		}
		sort(a+1,a+n[i]+1,cmp);
		for(int j=1;j<=n[i];j++){
			if(a[j].b>a[j].a&&a[j].b>a[j].c&&q2<n[i]/2){
				q2++;
				sum+=a[j].b;
			}
			else if(a[j].a>a[j].b&&a[j].a>a[j].c&&q1<n[i]/2){
				q1++;
				sum+=a[j].a;
			}
			else{
				q3++;
				sum+=a[j].c;
			}
			
		}
		q1=0;
		q2=0;
		q3=0;
		sort(a+1,a+n[i]+1,cmp1);
		for(int j=1;j<=n[i];j++){
			if(a[j].a>a[j].b&&a[j].a>a[j].c&&q1<n[i]/2){
				q1++;
				sum2+=a[j].a;
			}
			else if(a[j].b>a[j].a&&a[j].b>a[j].c&&q2<n[i]/2){
				q2++;
				sum2+=a[j].b;
			}
			else{
				q3++;
				sum2+=a[j].c;
			}
		}
		cout<<max(sum,sum2)<<endl;
	}
	return 0;
}
