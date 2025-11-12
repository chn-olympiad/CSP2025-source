#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
int pan1(int p1,int p2,int p3){
	if(p1>p2&&p1>p3){
		return 1;}
	else if(p2>p3)
		return 2;
	else 
		return 3;
	}
int q(int p1,int p2,int p3)	{
	int sa;
	if((p1>p2)&&(p1>p3)){
		sa=min((p1-p2),(p1-p3));
		return sa; 
		}
	else 
		return -1;
	}
int main(){
	struct aa{
	int a1;
	int b1;
	int c1;
	};
	freopen("club.in","r",stdin);
	freopen("club.out",'w',stdout);
	int t;
	cin>>t;
    while(t--){
	int sum=0,n,p[3]={0},a[N]={0},b1,c1;
	aa g[N];
	cin>>n;
	if(n<210){
		for(int i=0;i<n;i++){
			g[i].a1=0;
			g[i].b1=0;
			g[i].c1=0;	
		}
		for(int i=0;i<n;i++){
			cin>>g[i].a1>>g[i].b1>>g[i].c1;
			p[pan1(g[i].a1,g[i].b1,g[i].c1)]++;
			sum+=max(g[i].a1,max(g[i].b1,g[i].c1));
		}
		int k1=pan1(p[1],p[2],p[3]),k2=max(p[1],max(p[2],p[3]));
		if(k2<=n/2){cout<<sum;}
		else{
			int w[N]={0};
			for(int i=0;i<n;i++){
				if(k1==1&&(q(g[i].a1,g[i].b1,g[i].c1)>0))
					w[i]=q(g[i].a1,g[i].b1,g[i].c1);
				if(k1==2&&(q(g[i].b1,g[i].a1,g[i].c1)>0))
					w[i]=q(g[i].b1,g[i].a1,g[i].c1);
				if(k1==3&&(q(g[i].c1,g[i].b1,g[i].a1)>0))
					w[i]=q(g[i].c1,g[i].b1,g[i].a1);
				}
		sort(w,w+n);
		int j=0;
		for(int i=0;i<k2-n/2;i++){
			j++;
			sum-=w[j];
			if(w[j]==0)
				i--;
			}
		cout<<sum;
		}
	}else{
		sum=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b1>>c1;	
		}
		sort(a,a+n);
		for(int i=n-1;i>=n/2;i--){
			sum+=a[i];
		}
		cout<<sum;}
		puts("");
		}return 0;
		}
	
