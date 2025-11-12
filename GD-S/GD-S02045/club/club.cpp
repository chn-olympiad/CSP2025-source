#include <bits/stdc++.h>
using namespace std;
struct node {
	int a;
	int b;
	int c;
	int num;
} s[100005];
bool cmp1(node x,node y) {
	return x.a>y.a;
}
bool cmp2(node x,node y) {
	if(x.a==y.a) return x.b>y.b;
}
bool cmp3(node x,node y) {
	if(x.a==y.a && x.b==y.b) return x.c>y.c;
}
int n,t,x,y,s1,s2,s3,sum;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	for(int j=1; j<=n; j++) {
		scanf("%d",&t);
		for(int i=1; i<=t; i++) {
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			s[i].num=s[i].a+s[i].b+s[i].c;
		}
		sort(s+1,s+1+t,cmp1);
		//*
		s1=s2=s3=sum=0;
		for(int i=1; i<=t; i++) {
			x=max(s[i].a,max(s[i].b,s[i].c));
			if(x==s[i].a && s1<=t/2) {
				s1++;
				sum+=s[i].a;
			} else if(x==s[i].b && s2<=t/2) {
				s2++;
				sum+=s[i].b;
			} else if(x==s[i].c && s3<=t/2) {
				s3++;
				sum+=s[i].c;
			} else {
				if(x!=s[i].a && y!=s[i].a) {
					s1++;
					sum+=s[i].a;
				} else if(x!=s[i].a && y!=s[i].a) {
					s2++;
					sum+=s[i].b;
				} else if(x!=s[i].b && y!=s[i].b) {
					s3++;
					sum+=s[i].c;
				}
			}
		}
		printf("%d\n",sum);//*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
