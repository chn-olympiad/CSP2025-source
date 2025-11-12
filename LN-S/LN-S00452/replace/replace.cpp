#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,cnt1=0,cnt2=0,cnt3=0,ans=0,f=0,g;
struct node{
	int c1,c2,c3;
}a[100003];
bool cmp(node p,node q){return p.c2>q.c2;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].c1,&a[i].c2,&a[i].c3);
			if(a[i].c1==a[i].c3&&a[i].c1==0) continue;
			f=1;
		}
		if(f==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].c2;
			printf("%d\n",ans);
		}
		else{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				int k[3]={a[i].c1,a[i].c2,a[i].c3};
				sort(k,k+3);
				if(k[2]==a[i].c1&&cnt1<=n/2) cnt1++,ans+=k[2];
				else if(k[2]==a[i].c2&&cnt2<=n/2) cnt2++,ans+=k[2];
				else if(k[2]==a[i].c3&&cnt3<=n/2) cnt3++,ans+=k[2];
				else{
					ans+=k[1];
				}
			}
			printf("%d\n",ans);
		}
		cnt1=cnt2=cnt3=ans=f=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
