#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct node{
	long long a,b,c,index,in2;
}me[N];
long long t,n,ans[4],num[4],sp[N],spp=1,spi[N],spii=1;
int tepa=0,ants=0,t2=0,a2n=0;
bool cmp(node x,node y){
	return x.a>y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int e=1;e<=t;e++){
		cin>>n;
		int mxv=n/2;
		me[i].in2=0;
		for(int i=1;i<=n;i++){
			cin>>me[i].a>>me[i].b>>me[i].c;
			int aa=me[i].a,bb=me[i].b,cc=me[i].c;
			if(aa>bb){
				if(aa>cc) me[i].index=1;
				else me[i].index=3;
			}else{
				if(bb>cc) me[i].index=2;
				else me[i].index=3;
			}
		}
		sort(me+1,me+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(me[i].b==0 && me[i].c==0){
				tepa++;
				sp[spp]=me[i].a;
				spi[spii]=me[i].index;
			}
		}
		if(tepa==n){
			for(int i=1;i<=n/2;i++){
				ants+=me[i].a;
			}
			cout<<ants<<endl;
			tepa=0;
			ants=0;
			continue;
		}
		tepa=0;ants=0;
		for(int i=1;i<=n;i++){
			if(me[i].c==0){
				t2++;
			}
		}
		for(int i=1;i<=n;i++){
			int as=me[i].a,bn=me[i].b,cv=me[i].c;
			if(as>bn){
				if(as>cv && bn<cv){
					me[i].in2=3;
					me[i].c=bn;
					me[i].b=cv;
				}else if(as<cv){
					me[i].in2=1;
					me[i].a=cv;
					me[i].b=as;
					me[i].c=bn;
				}
			}else{
				if(as>cv){
					me[i].in2=1;
					me[i].a=bn;
					me[i].b=as;
				}else if(cv>bn){
					me[i].in2=2;
					me[i].a=cv;
					me[i].c=as;
				}else if(cv>as && cv<bn){
					me[i].in2=3;
					me[i].a=bn;
					me[i].b=cv;
					me[i].c=as;
				}
			}
			if(me[i].in2==0){
				me[i].in2=2;
			}
		}
		long long ss=0;
		if(t2==n){
			for(int i=1;i<=n;i++){
				int idd=me[i].index,iddd=me[i].in2;
				if(num[idd]<mxv){
					ss+=me[i].a;
				}else{
					ss+=me[i].b;
				}
			}
		}
		cout<<ss;
		ss=0;
		continue;
		sort(me+1,me+n+1,cmp);
		for(int i=1;i<=n;i++){
			int id=me[i].index,id2=me[i].in2;
			if(num[id]<mxv){
				ans[id]+=me[i].a;
				num[id]++;
			}else{
				ans[id2]+=me[i].b;
				num[id2]++;
			}
		}
		int s=ans[1]+ans[2]+ans[3];
		cout<<s<<endl;
		s=0;
		for(int i=1;i<=n;i++){
			me[i].a=0;
			me[i].b=0;
			me[i].c=0;
			me[i].index=0;
			me[i].in2=0;
		}
		ans[1]=0;ans[2]=0;ans[3]=0;num[1]=0;num[2]=0;num[3]=0;
	}
	return 0;
}