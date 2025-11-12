#include<bits/stdc++.h>
using namespace std;
int t,n,m,y,k,x;
struct abc{
	int a,b,c;
}h[111111];
int cmp1(abc a,abc b){
	return a.a>b.a;
}
int cmp2(abc a,abc b){
	return a.b>b.b;
}
int cmp3(abc a,abc b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		y=0,m=0,x=0,k=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&h[i].a,&h[i].b,&h[i].c);
		sort(h+1,h+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(h[i].a>h[i].b&&h[i].a>h[i].c&&x<n/2){
				m+=h[i].a;
				x++;
			}
			else if(h[i].b>h[i].c&&h[i].b>h[i].c&&y<n/2){
				m+=h[i].b;
				y++;
			}
			else m+=h[i].c;
		}
		k=m,y=0,m=0,x=0;
		sort(h+1,h+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(h[i].a>h[i].b&&h[i].a>h[i].c){
				m+=h[i].a;
				x++; 
			} 
			else if(h[i].b>h[i].c&&h[i].b>h[i].c&&y<n/2){
				m+=h[i].b;
				y++;
			}
			else m+=h[i].c;
		}
		k=max(k,m);
		m=0,y=0,x=0;
		sort(h+1,h+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(h[i].a>h[i].b&&h[i].a>h[i].c){
				m+=h[i].a;
				x++;
			}
			else if(h[i].b>h[i].c&&h[i].b>h[i].c&&y<n/2){
				m+=h[i].b;
				y++;
			}
			else m+=h[i].c;
		}
		k=max(k,m);
		printf("%d\n",k);
	}
	return 0;
} 
