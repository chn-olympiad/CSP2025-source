#include<bits/stdc++.h>
using namespace std;

struct node{
	int a,b,c;
	int mx,mxn,mn,mnn;
}p[100009];

int t;
int n;
node pa[100009],pb[100009],pc[100009];
int xba,xbb,xbc;
int ans1,ans2;

int gtmx(node i){
	if(i.a>=i.b&&i.a>=i.c) return i.a;
	else if(i.b>=i.a&&i.b>=i.c) return i.b;
	else return i.c;
}

int gtsd(node i){
	if(gtmx(i)==i.a){
		if(i.b>i.c) return i.b;
		else return i.c;
	}
	else if(gtmx(i)==i.b){
		if(i.a>i.c) return i.a;
		else return i.c;
	}
	else{
		if(i.a>i.b) return i.a;
		else return i.b;
	}
}

bool cmp(node i,node j){
	return gtmx(i)-gtsd(i)>gtmx(j)-gtsd(j);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		xba=xbb=xbc=0;
		ans1=ans2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			if(gtmx(p[i])==p[i].a){
				pa[++xba]=p[i];
			}
			else if(gtmx(p[i])==p[i].b){
				pb[++xbb]=p[i];
			}
			else pc[++xbc]=p[i];
		}
		if(xba>n/2){
			sort(pa+1,pa+xba+1,cmp);
			for(int i=xba;i>n/2;i--){
				ans2+=gtsd(pa[xba]);
				xba--;
			}
		}
		if(xbb>n/2){
			sort(pb+1,pb+xbb+1,cmp);
			for(int i=xbb;i>n/2;i--){
				ans2+=gtsd(pb[xbb]);
				xbb--;
			}
		}
		if(xbc>n/2){
			sort(pc+1,pc+xbc+1,cmp);
			for(int i=xbc;i>n/2;i--){
				ans2+=gtsd(pc[xbc]);
				xbc--;
			}
		}
//		cout<<xba<<" "<<xbb<<" "<<xbc<<endl;
		for(int i=1;i<=xba;i++) ans1+=gtmx(pa[i]);
//		cout<<ans1<<endl;
		for(int i=1;i<=xbb;i++) ans1+=gtmx(pb[i]);
//		cout<<ans1<<endl;
		for(int i=1;i<=xbc;i++) ans1+=gtmx(pc[i]);
		printf("%d\n",ans1+ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 