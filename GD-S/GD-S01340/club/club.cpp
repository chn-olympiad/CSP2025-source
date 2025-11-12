#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
bool f[100005];
struct f4{
	int id,num;
}s1[100005],s2[100005],s3[100005];
struct f1{
	int a1,a2,a3;
}a[100005];
int cmp(f4 x,f4 y){
	return x.num>y.num;
}
int cmp1(f1 x,f1 y){
	int fx=abs(x.a1-x.a2)+abs(x.a2-x.a3);
	int fy=abs(y.a1-y.a2)+abs(y.a2-y.a3);
	return fx>fy;
}
int cmp2(f1 x,f1 y){
	int fx=abs(x.a1-x.a2);
	int fy=abs(y.a1-y.a2);
	return fx>fy;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		int n,s=0,maxx2=0,maxx3=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
			maxx2=max(maxx2,a[i].a2);
			maxx3=max(maxx3,a[i].a3);
			s1[i].id=i,s1[i].num=a[i].a1;
			s2[i].id=i,s2[i].num=a[i].a2;
			s3[i].id=i,s3[i].num=a[i].a3;
		}
		sort(s1+1,s1+1+n,cmp);
		sort(s2+1,s2+1+n,cmp);
		sort(s3+1,s3+1+n,cmp);
		if(maxx2==0&&maxx3==0){
			for(int i=1;i<=n/2;++i) s+=s1[i].num;
			printf("%lld\n",s);
			continue;
		}
		if(maxx3==0){
			sort(a+1,a+1+n,cmp2);
			int d1=0,d2=0;
			for(int i=1;i<=n;++i){
				if(a[i].a1>=a[i].a2){
					if(d1==n/2){
						++d2;
						s+=a[i].a2;
					}
					else ++d1,s+=a[i].a1;
				}
				else{
					if(d2==n/2){
						++d1;
						s+=a[i].a1;
					}
					else ++d2,s+=a[i].a2;
				}
			}
			printf("%lld\n",s);
			continue;
		}
		if(n<=10){
			for(int cnt=0;cnt<pow(3,n);++cnt){
				int p=cnt,k=0,d1=0,d2=0,d3=0,sum=0;
				while(p){
					++k;
					if(p%3==0){
						++d1;
						sum+=a[k].a1;
					}
					else if(p%3==1){
						++d2;
						sum+=a[k].a2;
					}
					else if(p%3==2){
						++d3;
						sum+=a[k].a3;
					}
					p/=3;
				}
				for(int i=k+1;i<=n;i++){
					++d1;
					sum+=a[i].a1;
				}
				if(d1>n/2||d2>n/2||d3>n/2) continue;
				s=max(s,sum);
			}
			printf("%lld\n",s);
			continue;
		}
		if(n<=200){
			for(int d1=1;d1<=n/2;++d1)
				for(int d2=1;d2+d1<=n;++d2){
					int d3=n-d1-d2;
					if(d2>n/2||d3>n/2) continue;
					int j=0,sum=0,x=0;
					memset(f,true,sizeof(f));
					for(int i=1;j<d1;++i)
						if(f[s1[i].id]) f[s1[i].id]=false,++j,x+=s1[i].num;						
					j=0;
					for(int i=1;j<d2;++i)
						if(f[s2[i].id]) f[s2[i].id]=false,++j,x+=s2[i].num;
					j=0;
					for(int i=1;j<d3;++i)
						if(f[s3[i].id]) f[s3[i].id]=false,++j,x+=s3[i].num;
					sum=max(sum,x);
					memset(f,true,sizeof(f));
					j=0,x=0;
					for(int i=1;j<d1;++i)
						if(f[s1[i].id]) f[s1[i].id]=false,++j,x+=s1[i].num;
					j=0;
					for(int i=1;j<d3;++i)
						if(f[s3[i].id]) f[s3[i].id]=false,++j,x+=s3[i].num;
					j=0;
					for(int i=1;j<d2;++i)
						if(f[s2[i].id]) f[s2[i].id]=false,++j,x+=s2[i].num;
					sum=max(sum,x);
					memset(f,true,sizeof(f));
					j=0,x=0;
					for(int i=1;j<d2;++i)
						if(f[s2[i].id]) f[s2[i].id]=false,++j,x+=s2[i].num;
					j=0;
					for(int i=1;j<d1;++i)
						if(f[s1[i].id]) f[s1[i].id]=false,++j,x+=s1[i].num;
					j=0;
					for(int i=1;j<d3;++i)
						if(f[s3[i].id]) f[s3[i].id]=false,++j,x+=s3[i].num;
					sum=max(sum,x);
					memset(f,true,sizeof(f));
					j=0,x=0;
					for(int i=1;j<d2;++i)
						if(f[s2[i].id]) f[s2[i].id]=false,++j,x+=s2[i].num;
					j=0;
					for(int i=1;j<d3;++i)
						if(f[s3[i].id]) f[s3[i].id]=false,++j,x+=s3[i].num;
					j=0;
					for(int i=1;j<d1;++i)
						if(f[s1[i].id]) f[s1[i].id]=false,++j,x+=s1[i].num;
					sum=max(sum,x);
					memset(f,true,sizeof(f));
					j=0,x=0;
					for(int i=1;j<d3;++i)
						if(f[s3[i].id]) f[s3[i].id]=false,++j,x+=s3[i].num;
					j=0;
					for(int i=1;j<d1;++i)
						if(f[s1[i].id]) f[s1[i].id]=false,++j,x+=s1[i].num;
					j=0;
					for(int i=1;j<d2;++i)
						if(f[s2[i].id]) f[s2[i].id]=false,++j,x+=s2[i].num;
					sum=max(sum,x);
					memset(f,true,sizeof(f));
					j=0,x=0;
					for(int i=1;j<d3;++i)
						if(f[s3[i].id]) f[s3[i].id]=false,++j,x+=s3[i].num;
					j=0;
					for(int i=1;j<d2;++i)
						if(f[s2[i].id]) f[s2[i].id]=false,++j,x+=s2[i].num;
					j=0;
					for(int i=1;j<d1;++i)
						if(f[s1[i].id]) f[s1[i].id]=false,++j,x+=s1[i].num;
					sum=max(sum,x);
					s=max(s,sum);
				}
			printf("%lld\n",s);
			continue;
		}
		sort(a+1,a+1+n,cmp1);
		int d1=0,d2=0,d3=0;
		for(int i=1;i<=n;++i){
			if(a[i].a1>=a[i].a2>=a[i].a3){
				if(d1==n/2){
					++d2;
					s+=a[i].a2;
				}
				else ++d1,s+=a[i].a1;
			}
			else if(a[i].a1>=a[i].a3>=a[i].a2){
				if(d1==n/2){
					++d3;
					s+=a[i].a3;
				}
				else ++d1,s+=a[i].a1;
			}
			else if(a[i].a2>=a[i].a1>=a[i].a3){
				if(d2==n/2){
					++d1;
					s+=a[i].a1;
				}
				else ++d2,s+=a[i].a2;
			}
			else if(a[i].a2>=a[i].a3>=a[i].a1){
				if(d2==n/2){
					++d3;
					s+=a[i].a3;
				}
				else ++d2,s+=a[i].a2;
			}
			else if(a[i].a3>=a[i].a1>=a[i].a2){
				if(d3==n/2){
					++d1;
					s+=a[i].a1;
				}
				else ++d3,s+=a[i].a3;
			}
			else if(a[i].a3>=a[i].a2>=a[i].a1){
				if(d3==n/2){
					++d2;
					s+=a[i].a2;
				}
				else ++d3,s+=a[i].a3;
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
