#include<bits/stdc++.h>
using namespace std;
int n,t,x[100010],y[100010],f[100010],ans,k[100010];
struct peo{
	int a,b,c,d;
}a[100010];
struct tong{
	int h,w;
}z[100010];
bool cmp(peo ccf,peo fcc){
	return ccf.d>fcc.d;
}
bool cmpp(tong ccf,tong fcc){
	return ccf.w>fcc.w;
}
bool cmppp(int ccf,int fcc){
	return a[ccf].d>a[fcc].d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		int cnt=0,num=0,cs=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=a[i].a-a[i].b;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			x[++cnt]=i;
			y[++num]=i;
			z[i].w=a[i].c-max(a[i].a,a[i].b);
			z[i].h=i;
			//cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
		}
		for(int i=n/2+1;i<=n;i++){
			y[++num]=i;
			x[++cnt]=i;
			z[i].w=a[i].c-max(a[i].a,a[i].b);
			z[i].h=i;
		}
		sort(z+1,z+n+1,cmpp);
		//cout<<z[1].h<<a[z[1].h].b<<a[z[1].h].c<<"\n";
		for(int i=1;i<=n/2;i++){
			if(z[i].w>=0)
				ans+=a[z[i].h].c,f[z[i].h]=1;
			else{
				i=n+1;
			}
		}
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(f[i]==0)
				k[++cntt]=i;//,cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
		}
		sort(k+1,k+1+cntt,cmppp);
		int flag=0,l=0;
		for(int i=1;i<=cntt;i++){
			if((a[k[i]].a>=a[k[i]].b&&l<n/2)||cntt-i+1>n/2){
				ans+=a[k[i]].a,l++,f[k[i]]=1;
			}else if((l>=n/2)||(a[k[i]].a<a[k[i]].b&&cntt-i+1<=n/2)){
				flag=i;
				i=cntt+1;
			}
		}
		for(int i=flag;i<=cntt;i++){
			//if(f[k[i]]==0)
			ans+=a[k[i]].b;
		}
		cout<<ans<<"\n";
		ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;
			x[i]=0;
			y[i]=0;
			a[i].a=0;
			a[i].b=0;
			a[i].c=0;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
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
4 0 0*/
