#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long T,n,f[N][4],d[4];//b数组，用来记入其他max值 
struct node{
	long long a[4],b,c;
}r[N];
bool cmp1(node x1,node x2){
	if(x1.c==1&&x2.c==1){
		return (x1.a[1]-x1.b)>(x2.a[1]-x2.b);
	}else if(x1.c==1&&x2.c!=1){
		return 1;
	}else{
		return 0;
	}
}
bool cmp2(node x1,node x2){
	if(x1.c==2&&x2.c==2){
		return (x1.a[2]-x1.b)>(x2.a[2]-x2.b);
	}else if(x1.c==2&&x2.c!=2){
		return 1;
	}else{
		return 0;
	}
}
bool cmp3(node x1,node x2){
	if(x1.c==3&&x2.c==3){
		return (x1.a[3]-x1.b)>(x2.a[3]-x2.b);
	}else if(x1.c==3&&x2.c!=3){
		return 1;
	}else{
		return 0;
	}
}
int read(){
	char st;
	st=getchar();
	int x=0;
	while(st!=' '){
		int y=st-'0';
		x=x*10+y;
		st=getchar();
		cout<<st;
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long ans=0;
		scanf("%lld",&n);
		memset(d,0,sizeof d);
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&r[i].a[1],&r[i].a[2],&r[i].a[3]);
			if(r[i].a[1]>r[i].a[2]&&r[i].a[1]>r[i].a[3]){
				r[i].b=max(r[i].a[2],r[i].a[3]);
				r[i].c=1;
				d[1]++;
			}else if(r[i].a[2]>r[i].a[1]&&r[i].a[2]>r[i].a[3]){
				r[i].b=max(r[i].a[1],r[i].a[3]);
				r[i].c=2;
				d[2]++;
			}else if(r[i].a[3]>r[i].a[1]&&r[i].a[2]<r[i].a[3]){
				r[i].b=max(r[i].a[1],r[i].a[2]);
				r[i].c=3;
				d[3]++;
			}else{
				r[i].c=4;
			}
		}
		if(d[1]>=d[2]&&d[1]>=d[3]){
			sort(r+1,r+n+1,cmp1);
			int i=1,flag=1;
			for(i=1;i<=n/2;i++){
				if(r[i].c!=1){
					flag=0;
					break;
				}
				ans+=r[i].a[1];
			}
			for(;i<=n;i++){
				if(flag){
					ans+=max(r[i].a[2],r[i].a[3]);
				}else{
					ans+=r[i].a[r[i].c];
				}	
			}
			printf("%lld\n",ans);
		}else if(d[2]>=d[3]&&d[2]>=d[1]){
			sort(r+1,r+n+1,cmp2);
			int i=1,flag=1;
			for(i=1;i<=n/2;i++){
				if(r[i].c!=2){
					flag=0;
					break;
				}
				ans+=r[i].a[2];
			}
			for(;i<=n;i++){
				if(flag){
					ans+=max(r[i].a[1],r[i].a[3]);
				}else{
					ans+=r[i].a[r[i].c];
				}	
			}
			printf("%lld\n",ans);
		}else if(d[3]>=d[1]&&d[3]>=d[2]){
			sort(r+1,r+n+1,cmp3);
			int i=1,flag=1;
			for(i=1;i<=n/2;i++){
				if(r[i].c!=3){
					flag=0;
					break;
				}
				ans+=r[i].a[3];
			}
			for(;i<=n;i++){
				if(flag){
					ans+=max(r[i].a[1],r[i].a[2]);
				}else{
					ans+=r[i].a[r[i].c];
				}	
			}
			printf("%lld\n",ans);
		}	
	}
	return 0;
}
