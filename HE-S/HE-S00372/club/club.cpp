#include<bits/stdc++.h>
using namespace std;
int t;
const int N=100005;
struct node{
	int y;
	int r;
	int s;
}a[N];
int b[N],c[N],d[N],ansb,ansc,ansd,res;
bool cmp(int x,int w){
	if(x>w)return x>w;
	else return x<w;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d %d %d",&a[i].y,&a[i].r,&a[i].s);
		for(int i=0;i<n;i++){
			if(a[i].y>a[i].r&&a[i].y>a[i].s){
				b[i]=a[i].y;
			}
			if(a[i].r>a[i].y&&a[i].r>a[i].s){
				c[i]=a[i].r;
			} 
			if(a[i].s>a[i].y&&a[i].s>a[i].r){
				d[i]=a[i].s;
			}
		} 
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		sort(d,d+n,cmp);
		for(int i=0;i<n/2;i++){
			ansb+=b[i];
			ansc+=c[i];
			ansd+=d[i];
		}
		res=ansb+ansc+ansd;
		cout<<res;
		b[N]=0;
		c[N]=0;
		d[N]=0;
		ansb=0;
		ansc=0;
		ansd=0;
	}
	return 0;
} 
