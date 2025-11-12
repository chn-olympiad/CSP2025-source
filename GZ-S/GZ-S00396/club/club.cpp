//GZ-S00396 遵义新蒲新区天立 蒲杰豪 
#include<bits/stdc++.h>
using namespace std;
int t,c1r,c2r,c3r,tt,js,xq=0;
struct club{
	int c1x;
	int c2x;
	int c3x;
}a[100005]; 
void re(int a,int b,int c){
	int zs=max(max(a,b),c);
	xq+=zs;
	if(zs==a)c1r+=1;else
	if(zs==b)c2r+=1;else
	if(zs==c)c3r+=1;	
}
void rea(int a,int b,int c){
	int zs=max(c,b);
	if(zs==b){c1r--;xq-=a;c2r+=1;xq+=b;}else
	if(zs==c){c1r--;xq-=a;c3r+=1;xq+=c;}	
}
void reb(int a,int b,int c){
	int zs=max(a,c);
	if(zs==a){c2r--;xq-=b;c1r++;xq+=a;}else
	if(zs==c){c2r--;xq-=b;c3r++;xq+=c;}	
}
void rec(int a,int b,int c){
	int zs=max(a,b);
	if(zs==a){c3r--;xq-=c;c1r+=1;xq+=a;}else
	if(zs==b){c3r--;xq-=c;c2r+=1;xq+=b;}	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){xq=0;t--;
	int n;cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i].c1x>>a[i].c2x>>a[i].c3x;
	for(int i=1;i<=n;i++)
		re(a[i].c1x,a[i].c2x,a[i].c3x);
	if(c1r>n/2){tt=0;js=0;
		for(int i=1;i<=n;i++){
			if(a[i].c2x>=tt||a[i].c3x>=tt){
				tt=max(a[i].c2x,a[i].c3x);js=i;}
				}
			rea(a[js].c1x,a[js].c2x,a[js].c3x);
}else 	if(c2r>n/2){tt=0;js=0;
		for(int i=1;i<=n;i++){
			if(a[i].c1x>=tt||a[i].c3x>=tt){
				tt=max(a[i].c1x,a[i].c3x);js=i;}
				}
			reb(a[js].c1x,a[js].c2x,a[js].c3x);
	}else 	if(c3r>n/2){tt=0;js=0;
		for(int i=1;i<=n;i++){
			if(a[i].c1x>=tt||a[i].c2x>=tt){
				tt=max(a[i].c2x,a[i].c1x);js=i;}
				}
			rec(a[js].c1x,a[js].c2x,a[js].c3x);
			}
	cout<<xq<<endl;}
return 0;
}
