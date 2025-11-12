#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(p) freopen(#p".in","r",stdin),freopen(#p".out","w",stdout);
const int maxn=100001;
int t;
struct P{
	int ii;
	short a[3],c;
	short d[3][3];
};
P p[maxn],v[maxn/2];
bool c1(P a,P b){
	return (min(a.d[0][1],a.d[0][2])<min(b.d[0][1],b.d[0][2]));
}
bool c2(P a,P b){
	return (min(a.d[1][0],a.d[1][2])<min(b.d[1][0],b.d[1][2]));
}
bool c3(P a,P b){
	return (min(a.d[2][0],a.d[2][1])<min(b.d[2][0],b.d[2][1]));
}
int main(){
	fre(club);
	cin>>t;
	while(t--){
		ll ans=0;
		int n;
		cin>>n;
		int b[3]={0};
		for(int i=1;i<=n;++i){
			p[i].ii=i;
			scanf("%d %d %d",&p[i].a[0],&p[i].a[1],&p[i].a[2]);
			if(p[i].a[0]>=p[i].a[1]&&p[i].a[0]>=p[i].a[2]){
				p[i].c=0;
				b[0]++;
				ans+=p[i].a[0];
			}
			else if(p[i].a[1]>=p[i].a[2]&&p[i].a[1]>=p[i].a[0]){
				p[i].c=1;
				b[1]++;
				ans+=p[i].a[1];
			}
			else {
				p[i].c=2;
				b[2]++;
				ans+=p[i].a[2];
			}
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					p[i].d[j][k]=p[i].a[j]-p[i].a[k];
				}
			}
		}
		bool vis[3]={0};
		while(b[0]>n/2||b[1]>n/2||b[2]>n/2){
			if(b[0]>n/2&&vis[0]==0){
				vis[0]=1; 
				int q=0;
				for(int i=1;i<=n;++i){
					if(p[i].c==0){
						v[q]=p[i];
						q++;
					}
				}
				sort(v,v+q,c1);
				q=0;
				while(b[0]>n/2){
					b[0]--;
					p[v[q].ii].c=(p[v[q].ii].d[0][1]<p[v[q].ii].d[0][2]?1:2);
					b[p[v[q].ii].c]++;
					ans-=v[q].d[0][p[v[q].ii].c];
					q++;
				}
			}
			if(b[1]>n/2&&vis[1]==0){
				vis[1]=1; 
				int q=0;
				for(int i=1;i<=n;++i){
					if(p[i].c==1){
						v[q]=p[i];
						q++;
					}
				}
				sort(v,v+q,c2);
				q=0;
				while(b[1]>n/2){
					b[1]--;
					p[v[q].ii].c=(p[v[q].ii].d[1][0]<p[v[q].ii].d[1][2]?0:2);
					b[p[v[q].ii].c]++;
					ans-=v[q].d[1][p[v[q].ii].c];
					q++;
				}
			}
			if(b[2]>n/2&&vis[2]==0){
				vis[2]=1; 
				int q=0;
				for(int i=1;i<=n;++i){
					if(p[i].c==2){
						v[q]=p[i];
						q++;
					}
				}
				sort(v,v+q,c3);
				q=0;
				while(b[2]>n/2){
					b[2]--;
					p[v[q].ii].c=(p[v[q].ii].d[2][0]<p[v[q].ii].d[2][1]?0:1);
					b[p[v[q].ii].c]++;
					ans-=v[q].d[2][p[v[q].ii].c];
					q++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

