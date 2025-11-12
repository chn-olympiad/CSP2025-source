#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}a[N];
int t,n;
int ans;
bool cmpa(node i,node j){
	if((i.a-max(i.b,i.c))!=(j.a-max(j.b,j.c))) return (i.a-max(i.b,i.c))>(j.a-max(j.b,j.c));
	return i.a>j.a;
}
bool cmpb(node i,node j){
	if((i.b-max(i.a,i.c))!=(j.b-max(j.a,j.c))) return (i.b-max(i.a,i.c))>(j.b-max(j.a,j.c));
	return i.b>j.b;
}
bool cmpc(node i,node j){
	if((i.c-max(i.a,i.b))!=(j.c-max(j.a,j.b))) return (i.c-max(i.a,i.b))>(j.c-max(j.a,j.b));
	return i.c>j.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0; 
		int cnta=0,cntb=0,cntc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>max(a[i].b,a[i].c)) cnta++;
			else if(a[i].b>max(a[i].a,a[i].c)) cntb++;
			else cntc++;
		}
		if(cnta>n/2){
			sort(a+1,a+1+n,cmpa);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a; 
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=max(a[i].b,a[i].c);
			}
		}
		else if(cntb>n/2){
			sort(a+1,a+1+n,cmpb);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].b; 
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=max(a[i].a,a[i].c);
			}
		}
		else if(cntc>n/2){
			sort(a+1,a+1+n,cmpc);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].c; 
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=max(a[i].a,a[i].b);
			}
		}
		else{
			for(int i=1;i<=n;i++){
				ans+=max(a[i].a,max(a[i].b,a[i].c));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
10
2020 14533 18961 c
2423 15344 16322 c
1910 6224 16178  c
2038 9963 19722  c
8375 10557 5444  b
3518 14615 17976 c
6188 13424 16615 c
8769 509 4394    a
958 3195 9953    c
16441 5313 10926 a

*/
