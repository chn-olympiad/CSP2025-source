#include <bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int b;
	int c;
	int d;
};
int cmp(node bjx,node bjd){
	if(bjx.d<0 && bjd.d<0)return bjx.b<bjd.b;
	if(bjx.d>=0 && bjd.d>=0)return bjx.a>bjd.a;
	return bjx.d>bjd.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int p;
	cin>>p;
	for(int q=0;q<p;q++){
		int n,ans=0;
		cin>>n;
		node a[n];
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			ans+=a[i].c;
			a[i].a-=a[i].c;
			a[i].b-=a[i].c;
			a[i].c-=a[i].c;
			a[i].d=a[i].a-a[i].b;
		}
		sort(a,a+n,cmp);
		//for(int i=0;i<n;i++)cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<' '<<a[i].d<<endl;
		int as=0,bs=0;
		int xbz=0,xby=n-1;
		while(xbz<xby){
			int f=1;
			if(a[xbz].a>=0 && as<n/2){
				ans+=a[xbz].a;
				//cout<<a[xbz].a<<endl;
				as++;
				xbz++;
				f=0;
			}
			if(a[xby].b>=0 && bs<n/2){
				ans+=a[xby].b;
				//cout<<a[xby].b<<endl;
				bs++;
				xby--;
				f=0;
			}
			if(f){
				if(xbz+n-xby-1>=n/2){
					break;
				}else {
					if(a[xbz].a>a[xby].b){
						if(as<n/2){
							as++;
							ans+=a[xbz].a;
							//cout<<a[xbz].a<<endl;
							xbz++;
						}else{
							bs++;
							ans+=a[xby].b;
							//cout<<a[xby].b<<endl;
							xby--;
						}
					}else{
						if(bs<n/2){
							bs++;
							ans+=a[xby].b;
							//cout<<a[xby].b<<endl;
							xby--;
						}else{
							as++;
							ans+=a[xbz].a;
							//cout<<a[xbz].a<<endl;
							xbz++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
