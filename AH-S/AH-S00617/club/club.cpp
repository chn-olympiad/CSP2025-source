#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int y;
	int z;
	int o;
}a[200005];
int f1[200005];
long long f2[200005],id=0;
long long f3[200005],id2=0;
long long max_me(long long xx,long long yy){
	if(xx>yy) return xx;
	else return yy;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		memset(f3,0,sizeof(f3));
		id=0;id2=0;
		long long n,s1=0,s2=0,s3=0,ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			long long g=max(a[i].x,max(a[i].y,a[i].z));
			long long u;
			if(a[i].x==g) u=1;
			else if(a[i].y==g) u=2;
			else u=3;
			a[i].o=u;
			if(u==1) s1++;
			if(u==2) s2++;
			if(u==3) s3++;
			ans=ans+g;
		}
		if(s1>n/2){
			for(long long i=1;i<=n;i++){
				if(a[i].o==1){
					f1[++id]=a[i].y-a[i].x;
					f2[id]=a[i].z-a[i].x;
				}
			}
			s1=s1-n/2;
			for(long long i=1;i<=id;i++)
				f3[++id2]=max_me(f1[i],f2[i]);
			sort(f3+1,f3+id2+1);
			for(long long i=id2;i>=id2-s1+1;i--)
				ans+=f3[i];
		}
		else if(s2>n/2){
			for(long long i=1;i<=n;i++){
				if(a[i].o==2){
					f1[++id]=a[i].x-a[i].y;
					f2[id]=a[i].z-a[i].y;
				}
			}
			s2=s2-n/2;
			for(long long i=1;i<=id;i++)
				f3[++id2]=max_me(f1[i],f2[i]);
			sort(f3+1,f3+id2+1);
			for(long long i=id2;i>=id2-s2+1;i--)
				ans+=f3[i];
		}
		if(s3>n/2){
			for(long long i=1;i<=n;i++){
				if(a[i].o==3){
					f1[++id]=a[i].x-a[i].z;
					f2[id]=a[i].y-a[i].z;
				}
			}
			s3=s3-n/2;
			for(long long i=1;i<=id;i++)
				f3[++id2]=max_me(f1[i],f2[i]);
			sort(f3+1,f3+id2+1);
			for(long long i=id2;i>=id2-s3+1;i--)
				ans+=f3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
