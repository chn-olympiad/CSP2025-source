#include<bits/stdc++.h>
using namespace std;
int n,sum,s;
int a1;
int b1;
int c1;
struct node{
	int a;
	int b;
	int c;
}v[100010];
bool cmp(node x,node y){
	if(x.a==y.a&&x.b==y.b)return x.c>y.c;
	else if(x.a==y.a)return x.b>y.b;
	else return x.a>y.a;
}
void check(int m,int i){
	sum+=m;
	if(i==n){
		s=max(s,sum);
		sum-=m;
		i--;
		return;
	}
	i++;
	if(a1!=0){
		a1--;
		check(v[i].a,i);
		a1++;
	}
	if(b1!=0){
		b1--;
		check(v[i].b,i);
		b1++;
	} 
	if(c1!=0){
		c1--;
		check(v[i].c,i);
		c1++;
	}
	sum-=m;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		a1=b1=c1=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
		}
		sort(v+1,v+n+1,cmp);
		a1--;
		check(v[1].a,1);
		a1++;
		sum=0;
		b1--;
		check(v[1].b,1);
		b1++;
		sum=0;
		c1--;
		check(v[1].c,1);
		c1++;
		printf("%d\n",s);
		s=0;
		sum=0;
	}
	return 0;
}
