#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define ll long long
struct node{
	int a,b,c,max,sum,min,mid,s;
	double m;
}p[N];
int T;
int n;
int f1,f2,f3;
ll ans;
bool cmp(node x,node y){
	if(x.m == y.m){
		return x.max>y.max;
	}
	return x.m>y.m;
}
int maxx(int a,int b,int c){
	int x = max(a,b);
	return max(x,c);
}
int minn(int a,int b,int c){
	int x = min(a,b);
	return min(x,c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans = 0;
		f1 = 0,f2 = 0,f3 = 0;
		cin>>n;
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
			p[i].sum = p[i].a+p[i].b+p[i].c;
			p[i].max = maxx(p[i].a,p[i].b,p[i].c);
			p[i].min = minn(p[i].a,p[i].b,p[i].c);
			p[i].mid = p[i].sum-p[i].max-p[i].min;
			if(p[i].mid == 0)p[i].m = p[i].max;
			else p[i].m = p[i].max-p[i].mid;
			//p[i].s = p[i].a*p[i].b*p[i].c;
			
		}
		sort(p+1,p+1+n,cmp);
		//for(int i = 1;i<=n;i++)cout<<p[i].max<<" "<<p[i].mid<<" "<<p[i].min<<endl;
		for(int i = 1;i<=n;i++){
		//	cout<<p[i].max<<endl;
			if(p[i].max == p[i].a){
				if(f1<(n/2)){
					ans+=p[i].max;
					f1++;
				}
				else ans+=p[i].mid;
			//	cout<<ans<<" "<<1<<endl;
			}else if(p[i].max == p[i].b){
				if(f2<(n/2)){
					ans+=p[i].max;
					f2++;
				}
				else ans+=p[i].mid;
			//	cout<<ans<<" "<<2<<endl;
			}else{
				if(f3<(n/2)){
					ans+=p[i].max;
					f3++;
				}
				else ans+=p[i].mid;
				//cout<<ans<<" "<<3<<endl;
			}
			//cout<<ans<<endl;	
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
