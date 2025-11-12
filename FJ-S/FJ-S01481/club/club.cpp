#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct e{
	int a,b,c;
}v[100005];
bool cmp1(int x,int y){
	return x>y;
}
bool cmp2(e x,e y){
	int xx,yy;
	if(x.a>=x.b && x.a>=x.c){
		xx=x.a-max(x.b,x.c);
	}else if(x.b>=x.a && x.b>=x.c){
		xx=x.b-max(x.a,x.c);
	}else{
		xx=x.c-max(x.a,x.b);
	}
	if(y.a>=y.b && y.a>=y.c){
		yy=y.a-max(y.b,y.c);
	}else if(y.b>=y.a && y.b>=y.c){
		yy=y.b-max(y.a,y.c);
	}else{
		yy=y.c-max(y.a,y.b);
	}
	return xx>yy;
}
int main(){
	//freopen("club1.in","r",stdin);
	//freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int bo=0,co=0,ao=0;
		memset(v,0,sizeof(v));
		ans=0;
		for(int j=1;j<=n;j++){
			cin>>v[j].a>>v[j].b>>v[j].c;
			if(v[j].b!=0) bo=1;
			if(v[j].c!=0) co=1;
			if(v[j].a!=0) ao=1;
		}
		if(!bo && !co){
			int a[100005];
		    memset(a,0,sizeof(a));
			for(int j=1;j<=n;j++){
			    a[j]=v[j].a;
			}
			sort(a+1,a+1+n,cmp1);
			for(int j=1;j<=n/2;j++){
				ans+=a[j];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(!ao && !co){
			int k[100005];
		    memset(k,0,sizeof(k));
			for(int j=1;j<=n;j++){
			    k[j]=v[j].b;
			}
			sort(k+1,k+1+n,cmp1);
			for(int j=1;j<=n/2;j++){
				ans+=k[j];
			}
			cout<<ans<<'\n';
			continue;
		}
		sort(v+1,v+1+n,cmp2);
		int fp=0,sp=0,tp=0;
		for(int j=1;j<=n;j++){
			int fpp=v[j].a,spp=v[j].b,tpp=v[j].c;
			if(((sp>n/2 && fpp>=tpp) || (tp>n/2 && fpp>=spp) || (fpp>=spp && fpp>=tpp)) && fp<=n/2){
				ans+=fpp;
				fp+=1;
			}else if(((fp>n/2 && spp>=tpp) || (tp>n/2 && spp>=fpp) || (spp>=fpp && spp>=tpp)) && sp<=n/2){
				ans+=spp;
				sp+=1;
			}else if(((sp>n/2 && tpp>=fpp) || (fp>n/2 && tpp>=spp) || (tpp>=spp && tpp>=fpp)) && tp<=n/2){
				ans+=tpp;
				tp+=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
