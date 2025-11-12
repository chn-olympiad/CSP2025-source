#include<bits/stdc++.h>
using namespace std;
int n;
int p[4];
struct node{
	int i1,i2,i3,i4,xl1,xl2,xl3;
}a[100010];
struct tr{
	int i1,xh;
}h[4];
int k[100010][10];
bool cmp1(tr x,tr y){
	return x.i1>y.i1;
}
bool cmp(node x,node y){
	return x.i4>y.i4;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i12=1;i12<=t;++i12){
		memset(k,0,sizeof k);
		memset(h,0,sizeof h);
	long long s=0;
	p[1]=0,p[2]=0,p[3]=0;
	cin>>n;
	int w=n/2;
	for(int i=1;i<=n;++i){
	//	cin>>
		scanf("%d%d%d",&a[i].i1,&a[i].i2,&a[i].i3);
		//int t1=a[i].i1,t2=a[i].i2,t3=a[i].i3;
		h[1].i1=a[i].i1,h[2].i1=a[i].i2,h[3].i1=a[i].i3;
		h[1].xh=1,h[2].xh=2,h[3].xh=3;
		sort(h+1,h+1+3,cmp1);
		a[i].i1=h[1].i1;
		a[i].xl1=h[1].xh;
		a[i].i2=h[2].i1;
		a[i].xl2=h[2].xh;
		a[i].i3=h[3].i1;
		a[i].xl3=h[3].xh;
	//	int q[3]={t1,t2,t3};
	//	sort(q,q+3);
		a[i].i4=h[1].i1-h[2].i1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		h[1].i1=a[i].i1,h[2].i1=a[i].i2,h[3].i1=a[i].i3;
		h[1].xh=a[i].xl1,h[2].xh=a[i].xl2,h[3].xh=a[i].xl3;
		//sort(h+1,h+1+3,cmp1);
		if(h[1].i1!=h[2].i1){
			if(p[h[1].xh]<w){
				p[h[1].xh]++;
				s+=h[1].i1;
			}
			else{
				if(h[2].i1!=h[3].i1){
					p[h[2].xh]++;
					s+=h[2].i1;
				}
				else{
					s+=h[2].i1;
				}
			}
		}
		else{
			s+=h[1].i1;
		}
	}	
	cout<<s<<endl;
	}
	return 0;
}
