#include<bits/stdc++.h> 
using namespace std;
int t,n,num;
struct myd{
	int a,b,c,maxn;
}x[100005];
bool cmp(myd x,myd y){
	return x.maxn>y.maxn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		num=0;
		int x1=0,x2=0,x3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			x[i].maxn=max(max(x[i].a,x[i].b),x[i].c);
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(x[i].a>x[i].b&&x[i].a>x[i].c){
				if(x1<n/2){
					x1++;
					num+=x[i].a;
				}else if((x[i].b>x[i].c&&x2<n/2)||x3==n/2){
					x2++;
					num+=x[i].b;
				}else{
					x3++;
					num+=x[i].c;
				}
			}
			if(x[i].b>x[i].a&&x[i].b>x[i].c){
				if(x2<n/2){
					x2++;
					num+=x[i].b;
				}else if((x[i].a>x[i].c&&x1<n/2)||x3==n/2){
					x1++;
					num+=x[i].a;
				}else{
					x3++;
					num+=x[i].c;
				}
			}
			if(x[i].c>x[i].b&&x[i].c>x[i].a){
				if(x3<n/2){
					x3++;
					num+=x[i].c;
				}else if((x[i].b>x[i].a&&x2<n/2)||x1==n/2){
					x2++;
					num+=x[i].b;
				}else{
					x1++;
					num+=x[i].a;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
