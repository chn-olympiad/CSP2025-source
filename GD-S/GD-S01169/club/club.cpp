#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
	int d,e;
}abc[100001];
bool cmp(int a,int b){return a>b;}
bool cmp2(Node a1,Node b1){
	if(a1.d>b1.d)return true;
	return false;
}
int k,nm[5];
int m,n,a1,b1,c1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m); 
		k=0;c1=0;a1=0;b1=0;
		for(int j=1;j<=m;j++) scanf("%d%d%d",&abc[j].a,&abc[j].b,&abc[j].c);
		for(int j=1;j<=m;j++) {
			nm[1]=abc[j].a;	nm[2]=abc[j].b;	nm[3]=abc[j].c;
			sort(nm+1,nm+4,cmp);
			abc[j].d=nm[1]-nm[2];
			abc[j].e=nm[1];
		}
		sort(abc+1,abc+1+m,cmp2);
		for(int j=1;j<=m;j++) {
			k=k+abc[j].e;
			if(abc[j].e==abc[j].c)c1++;
			else if(abc[j].e==abc[j].a)a1++;
			else if(abc[j].e==abc[j].b)b1++;
			if(c1==m/2||b1==m/2||a1==m/2)
			j++;
				if(a1==m/2)
					for(;j<=m;j++) 
					k=k+max(abc[j].b,abc[j].c);
				else if(b1==m/2)
					for(;j<=m;j++) 
					k=k+max(abc[j].a,abc[j].c);
				else if(c1==m/2)
					for(;j<=m;j++) 
					k=k+max(abc[j].b,abc[j].a);
		}
		printf("%d\n",k);
	}
	return 0;
}
