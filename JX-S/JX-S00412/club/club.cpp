#include<bits/stdc++.h>

#define ll long long
#define rui /*register unsigned */int
#define ris(x,y,z) for(rui x=y;x<y+1;++x)
#define ful(x,y,z) for(rui x=y;x>y-1;--x)
#define db double

using namespace std;

const ll N=1e5+5;

ll n,vis[N],ans,a1,a2,a3,a[N][4],an[4]={0,0,0,0};

struct happy{
	ll i,a;
}d1[N],d2[N],d3[N];

char cmp(happy a,happy b){
	return a.a>b.a; 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=a1=a2=a3=0;
		ll max2=-1,max3=-1;
		for(int i=1;i<=n;++i){
			d1[i].a=d2[i].a=d3[i].a=0;
			d1[i].i=d2[i].i=d3[i].i=0;
		}
		memset(vis,1,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>d1[i].a;
			cin>>d2[i].a;
			cin>>d3[i].a;
			a[i][1]=d1[i].a;
			a[i][2]=d2[i].a;
			a[i][3]=d3[i].a;
			max2=max(max2,d2[i].a);
			max3=max(max3,d3[i].a);
			d1[i].i=d2[i].i=d3[i].i=i;
		}
		if(n==2){
			ll maxn=-1;
			for(int i=1;i<=3;++i){
				for(int j=1;j<=3;++j){
					if(i!=j){
						maxn=max(maxn,a[1][i]+a[2][j]);
					}
				}
			}
			cout<<maxn<<endl;
			continue;
		}
		if(n==4){
			ll maxn=-1;
			for(int i1=1;i1<=3;++i1){
				an[i1]+=1;
				for(int i2=1;i2<=3;++i2){
					an[i2]+=1;
					for(int i3=1;i3<=3;++i3){
						an[i3]+=1;
						for(int i4=1;i4<=3;++i4){
							an[i4]+=1;
							if(an[1]<=2&&an[2]<=2&&an[3]<=2&&an[4]<=2){
								maxn=max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]);
							}
							an[i4]-=1;
						}
						an[i3]-=1;
					}
					an[i2]-=1;
				}
				an[i1]-=1;
			}
			cout<<maxn<<endl;
			continue;
		}
		if(n==10){
			ll maxn=-1;
			for(int i1=1;i1<=3;++i1){
			an[i1]+=1;
			for(int i2=1;i2<=3;++i2){
			an[i2]+=1;
			for(int i3=1;i3<=3;++i3){
			an[i3]+=1;
			for(int i4=1;i4<=3;++i4){
			an[i4]+=1;
			for(int i5=1;i5<=3;++i5){
			an[i5]+=1;
			for(int i6=1;i6<=3;++i6){
			an[i6]+=1;
			for(int i7=1;i7<=3;++i7){
			an[i7]+=1;
			for(int i8=1;i8<=3;++i8){
			an[i8]+=1;
			for(int i9=1;i9<=3;++i9){
			an[i9]+=1;
			for(int i10=1;i10<=3;++i10){
			an[i10]+=1;
			if(an[1]<=5&&an[2]<=5&&an[3]<=5&&an[4]<=5&&an[5]<=5&&an[6]<=5&&an[7]<=5&&an[8]<=5&&an[9]<=5&&an[10]<=5){
				maxn=max(maxn,a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10]);
			}
			an[i10]-=1;
			}
			an[i9]-=1;
			}
			an[i8]-=1;
			}
			an[i7]-=1;
			}
			an[i6]-=1;
			}
			an[i5]-=1;
			}
			an[i4]-=1;
			}
			an[i3]-=1;
			}
			an[i2]-=1;
			}
			an[i1]-=1;
			}
		}
		/*
			4
			0 1 0
			0 1 0
			0 2 0
			0 2 0
		*/
		sort(d1+1,d1+1+n,cmp);
		sort(d2+1,d2+1+n,cmp);
		sort(d3+1,d3+1+n,cmp);
		if(max2==0&&max3==0){
			for(int i=1;i<=n/2;++i){
				ans+=d1[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		ll i1=1,i2=1,i3=1,Nn=n/2;
		for(int i=1;i<=n;++i){
			while(!vis[i1])
				++i1;
			while(!vis[i2])
				++i2;
			while(!vis[i3])
				++i3;
			if(d1[i1].a>=d2[i2].a&&d1[i1].a>=d3[i3].a&&Nn>=a1){
				++a1;
				ans+=d1[i1].a;
				//cout<<d1[i1].a<<"\n";
				vis[d1[i1].i]=0;
			}
			else if(d1[i1].a<=d2[i2].a&&d2[i2].a>=d3[i3].a&&Nn>=a2){
				++a2;
				ans+=d2[i2].a;
				//cout<<d2[i2].a<<"\n";
				vis[d2[i2].i]=0;
			}
			else if(d3[i1].a>=d2[i2].a&&d1[i1].a<=d3[i3].a&&Nn>=a3){
				++a3;
				ans+=d3[i3].a;
				//cout<<d3[i3].a<<"\n";
				vis[d3[i3].i]=0;
			}	
		}
		cout<<ans/*<<' '<<a1<<' '<<a2<<' '<<a3*/<<endl;
	}
	return 0;
}
