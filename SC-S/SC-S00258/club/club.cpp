#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int cs=1e5+6;
struct nodea{
	int date;
	int g;
	int bb;
	int cc;
}a[cs];
struct nodeb{
	int date;
	int g;
	int aa;
	int cc;
}b[cs];
struct nodec{
	int date;
	int g;
	int aa;
	int bb;
}c[cs];
bool f[cs];
int x,y,z,minx;
long long ans;
int top1,top2,top3;
int suma,sumb,sumc;
bool cmpa(nodea xx,nodea yy){
	if(xx.date==yy.date){
		if(xx.bb==yy.bb){
			return xx.cc<yy.cc;
		}
		if(xx.cc==yy.cc){
			return xx.bb<yy.bb;
		}
		if(xx.bb>xx.cc&&xx.bb>yy.bb&&xx.bb>yy.cc){
			return xx.bb<yy.bb;
		}
		if(xx.cc>xx.bb&&xx.cc>yy.bb&&xx.cc>yy.cc){
			return xx.cc<yy.cc;
		}
		if(yy.bb>xx.bb&&yy.bb>xx.cc&&yy.bb>yy.cc){
			return xx.bb<yy.bb;
		}
		if(yy.cc>xx.bb&&yy.cc>xx.cc&&yy.cc>yy.bb){
			return xx.cc<yy.cc;
		}
	}
	return xx.date>yy.date;
}
bool cmpb(nodeb xx,nodeb yy){
	if(xx.date==yy.date){
		if(xx.aa==yy.aa){
			return xx.cc<yy.cc;
		}
		if(xx.cc==yy.cc){
			return xx.aa<yy.aa;
		}
		if(xx.aa>xx.cc&&xx.aa>yy.aa&&xx.aa>yy.cc){
			return xx.aa<yy.aa;
		}
		if(xx.cc>xx.aa&&xx.cc>yy.aa&&xx.cc>yy.cc){
			return xx.cc<yy.cc;
		}
		if(yy.aa>xx.aa&&yy.aa>xx.cc&&yy.aa>yy.cc){
			return xx.aa<yy.aa;
		}
		if(yy.cc>xx.aa&&yy.cc>xx.cc&&yy.cc>yy.aa){
			return xx.cc<yy.cc;
		}
	}
	return xx.date>yy.date;
}
bool cmpc(nodec xx,nodec yy){
	if(xx.date==yy.date){
		if(xx.aa==yy.aa){
			return xx.bb<yy.bb;
		}
		if(xx.bb==yy.bb){
			return xx.aa<yy.aa;
		}
		if(xx.aa>xx.bb&&xx.aa>yy.aa&&xx.aa>yy.bb){
			return xx.aa<yy.aa;
		}
		if(xx.bb>xx.aa&&xx.bb>yy.aa&&xx.bb>yy.bb){
			return xx.bb<yy.bb;
		}
		if(yy.aa>xx.aa&&yy.aa>xx.bb&&yy.aa>yy.bb){
			return xx.aa<yy.aa;
		}
		if(yy.bb>xx.aa&&yy.bb>xx.bb&&yy.bb>yy.aa){
			return xx.bb<yy.bb;
		}
	}
	return xx.date>yy.date;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			f[i]=true;
			cin>>x>>y>>z;
			minx=min(x,min(y,z));
			ans+=minx;
			//差值 
			a[i].date=x-minx;
			b[i].date=y-minx;
			c[i].date=z-minx;
			//归属人 
			a[i].g=i;
			b[i].g=i;
			c[i].g=i;
			//a中的b与c
			a[i].bb=y-minx;
			a[i].cc=z-minx;
			//b中的a与c
			b[i].aa=x-minx;
			b[i].cc=z-minx;
			//c中的a与b
			c[i].aa=x-minx;
			c[i].bb=x-minx; 
		} 
		sort(a+1,a+n+1,cmpa);
		sort(b+1,b+n+1,cmpb);
		sort(c+1,c+n+1,cmpc);
		top1=0;
		top2=0;
		top3=0;	
		suma=0;
		sumb=0;
		sumc=0;
/*		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<a[i].date<<' '<<b[i].date<<' '<<c[i].date<<endl;
		}*/
		while((suma+sumb+sumc)<n){
			if(a[top1+1].date>=b[top2+1].date&&a[top1+1].date>=c[top3+1].date){
				if(top1<n/2&&f[a[top1+1].g]){
					ans+=a[top1+1].date;
					f[a[top1+1].g]=false;
					suma++;
				}
				top1++;
				if(top1==n/2){
					a[top1+1].date=-1;
				}	
			}else if(b[top2+1].date>=a[top1+1].date&&b[top2+1].date>=c[top3+1].date){
				if(top2<n/2&&f[b[top2+1].g]){
					ans+=b[top2+1].date;
					f[b[top2+1].g]=false;
					sumb++;
				}
				top2++;
				if(top2==n/2){
					b[top2+1].date=-1;
				}	
			}else if(c[top3+1].date>=b[top2+1].date&&c[top3+1].date>=a[top1+1].date){
				if(top3<n/2&&f[c[top3+1].g]){
					ans+=c[top3+1].date;
					f[c[top3].g]=false;
					sumc++;
				}
				top3++;
				if(top3==n/2){
					c[top3+1].date=-1;
				}	
			}			
		}
		cout<<ans<<endl;
	}
	return 0;
} 