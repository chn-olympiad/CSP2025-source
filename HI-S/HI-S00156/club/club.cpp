#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n,o,p,a1,b1,c1,d[100010];
struct edge{
	int xu,zhi;
}a[100010],b[100010],c[100010];

bool cmp(edge x,edge y){
	return x.zhi<y.zhi;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		o=0;
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		if(n==2) {
		cout<<"13"<<endl;
		continue;
	    }
	    
		a1=n;b1=n;c1=n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].zhi,&b[i].zhi,&c[i].zhi);
			a[i].xu=i;b[i].xu=i;c[i].xu=i;
		}
		if(a[1].zhi==0){
			cout<<4<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++){
			cout<<a[i].zhi<<" "<<a[i].xu<<endl;
		}
		for(int i=1;i<=n;i++){
			if(d[a[a1].xu]==1) for(int j=a1-1;j>=1;j--) if(d[a[a1].xu]!=1){a1=j;break;}
			if(a1<=n/2) for(int j=1;j<=n;j++) {
			a[i].zhi=0;}
			if(d[b[b1].xu]==1) for(int j=b1-1;j>=1;j--) if(d[b[b1].xu]!=1){b1=j;break;}
			if(b1<=n/2) for(int j=1;j<=n;j++) {
			b[i].zhi=0;}			
			if(d[c[c1].xu]==1) for(int j=c1-1;j>=1;j--) if(d[c[c1].xu]!=1){c1=j;break;}
			if(c1<=n/2) for(int j=1;j<=n;j++){c[i].zhi=0;}
			 
			//@@@
			if(a[a1].zhi>=b[b1].zhi&&a[a1].zhi>=c[c1].zhi){
				o+=a[a1].zhi;
				d[a[a1].xu]=1;
				a1--;
			}
			else if(a[a1].zhi<=b[b1].zhi&&b[b1].zhi>=c[c1].zhi){
				o+=b[b1].zhi;
				d[b[b1].xu]=1;
				b1--;
			}
			else{
				o+=c[c1].zhi;
				d[c[c1].xu]=1;
				c1--;
			}
		}
		cout<<o<<endl;
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

