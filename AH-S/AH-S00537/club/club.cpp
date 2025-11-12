#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d,e,f;
}cha[100010];
bool cmp(node a,node b){
	if(a.a!=b.a) return a.a>b.a;
	else if(a.b!=b.b) return a.b>b.b;
	else return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		int she1=0,she2=0,she3=0;
		memset(cha,0,sizeof(cha));
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cha[i].d>>cha[i].e>>cha[i].f;
			int u,v,w;
			if(cha[i].d>=cha[i].e&&cha[i].e>=cha[i].f){
				u=cha[i].d,v=cha[i].e,w=cha[i].f;
			}else if(cha[i].d>=cha[i].f&&cha[i].f>=cha[i].e){
				u=cha[i].d,v=cha[i].f,w=cha[i].e;
				//swap(cha[i].e,cha[i].f);
			}else if(cha[i].e>=cha[i].d&&cha[i].d>=cha[i].f){
				u=cha[i].e,v=cha[i].d,w=cha[i].f;
				//swap(cha[i].e,cha[i].d);
			}else if(cha[i].e>=cha[i].f&&cha[i].f>=cha[i].d){
				u=cha[i].e,v=cha[i].f,w=cha[i].d;
				//swap(cha[i].e,cha[i].d);
				//swap(cha[i].e,cha[i].f);
			}else if(cha[i].f>=cha[i].e&&cha[i].e>=cha[i].d){
				u=cha[i].f,v=cha[i].e,w=cha[i].d;
				//swap(cha[i].d,cha[i].f);
			}else if(cha[i].f>=cha[i].d&&cha[i].d>=cha[i].e){
				u=cha[i].f,v=cha[i].d,w=cha[i].e;
				//swap(cha[i].d,cha[i].f);
				//swap(cha[i].e,cha[i].f);
			}
			cha[i].a=u-w;
			cha[i].b=max(u-v,v-w);
			cha[i].c=min(u-v,v-w);
		}
		sort(cha+1,cha+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cha[i].d>=cha[i].e&&cha[i].e>=cha[i].f){
				if(she1<n/2){
					she1++;
					ans+=cha[i].d;
				}else if(she2<n/2){
					she2++;
					ans+=cha[i].e;
				}else{
					she3++;
					ans+=cha[i].f;
				}
			}else if(cha[i].d>=cha[i].f&&cha[i].f>=cha[i].e){
				if(she1<n/2){
					she1++;
					ans+=cha[i].d;
				}else if(she3<n/2){
					she3++;
					ans+=cha[i].f;
				}else{
					she2++;
					ans+=cha[i].e;
				}
			}else if(cha[i].e>=cha[i].d&&cha[i].d>=cha[i].f){
				if(she2<n/2){
					she2++;
					ans+=cha[i].e;
				}else if(she1<n/2){
					she1++;
					ans+=cha[i].d;
				}else{
					she3++;
					ans+=cha[i].f;
				}
			}else if(cha[i].e>=cha[i].f&&cha[i].f>=cha[i].d){
				if(she2<n/2){
					she2++;
					ans+=cha[i].e;
				}else if(she3<n/2){
					she3++;
					ans+=cha[i].f;
				}else{
					she1++;
					ans+=cha[i].d;
				}
			}else if(cha[i].f>=cha[i].e&&cha[i].e>=cha[i].d){
				if(she3<n/2){
					she3++;
					ans+=cha[i].f;
				}else if(she2<n/2){
					she2++;
					ans+=cha[i].e;
				}else{
					she1++;
					ans+=cha[i].d;
				}
			}else if(cha[i].f>=cha[i].d&&cha[i].d>=cha[i].e){
				if(she3<n/2){
					she3++;
					ans+=cha[i].f;
				}else if(she1<n/2){
					she1++;
					ans+=cha[i].d;
				}else{
					she2++;
					ans+=cha[i].e;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
