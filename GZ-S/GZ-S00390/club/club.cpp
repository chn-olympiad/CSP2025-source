//GZ-S00390  董云旗  遵义市老城小学
#include<bits/stdc++.h>
using namespace std;
struct Xx{
	int q,w,e,mx,cx;
}a[100001];
int T;
bool cmp1(Xx x,Xx y){
	if(x.q==y.q)return x.q>y.e;
	else return x.q>y.q;
}
//bool cmp2(Xx x,Xx y){
//	if(x.mx+x.cx==y.mx+y.cx)return x.mx>y.mx;
//	else  return x.mx+x.cx>y.mx+y.cx;
//}
bool cmp2(Xx x,Xx y){
	if(x.e==y.e && x.w==y.w)return x.q>y.q;
	else if(x.e==y.e)return x.w>y.w;
	else return x.e>y.e;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int x,y,z;
		bool mv=true;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(y!=0 || z!=0)mv=false;
			a[i].q=x,a[i].w=y,a[i].e=z;
			int sum=x+y+z;
			a[i].mx=max(x,max(y,z));
			a[i].cx=sum-(a[i].mx+min(x,min(y,z)));
		}
		if(mv){
			sort(a+1,a+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i].q;
			cout<<ans<<endl;
		}else if (n==2){
			if((a[1].mx==a[1].q && a[2].mx==a[2].q) || (a[1].mx==a[1].w && a[2].mx==a[2].w) || (a[1].mx==a[1].e && a[2].mx==a[2].e)){
				cout<<max(a[1].mx+a[2].cx,a[2].mx+a[1].cx);
			}else{
				cout<<a[1].mx+a[2].mx;
			}
		}else{
			int k=0,l=0,kl=0,ans=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(a[i].q==a[i].mx){
					if(k<n/2){
						k++;
						ans+=a[i].mx;
					}else{
						if(a[i].w==a[i].cx)l++;
						else kl++;
						ans+=a[i].cx;
					}
				}else if(a[i].w==a[i].mx){
					if(l<n/2){
						l++;
						ans+=a[i].mx;
					}else{
						if(a[i].q==a[i].cx)k++;
						else kl++;
						ans+=a[i].cx;
					}
				}else{
					if(kl<n/2){
						kl++;
						ans+=a[i].mx;
					}else{
						if(a[i].w==a[i].cx)kl++;
						else k++;
						ans+=a[i].cx;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
