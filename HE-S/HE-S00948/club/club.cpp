#include <bits/stdc++.h>
using namespace std;
int t,n,ans,m1,m2,s1max,s1min,s2max,s2min,c[3],N;
struct node{
	int a[3],k[3];
}p[100005];
inline same_1(node s1,node s2){
	s1min=min(min(s2.k[0],s2.k[1]),s2.k[2]),s2min=min(min(s2.k[0],s2.k[1]),s2.k[2]);
	if(s1.k[0]!=s1max&&s1.k[0]!=s1min) m1=s1.k[0];
	else if(s1.k[1]!=s1max&&s1.k[1]!=s1min) m1=s1.k[1];
	else m1=s1.k[2];
	if(s2.k[0]!=s2max&&s2.k[0]!=s2min) m2=s2.k[0];
	else if(s2.k[1]!=s2max&&s2.k[1]!=s2min) m2=s2.k[1];
	else m2=s2.k[2];
	if(m1!=m2) return m1>m2;
	else if(s1min!=s2min) return s1min>s2min;
	else return max(max(s1.a[0],s1.a[1]),s1.a[2])>max(max(s2.a[0],s2.a[1]),s2.a[2]);
}
inline bool cmp(node s1,node s2){
	s1max=max(max(s1.k[0],s1.k[1]),s1.k[2]),s2max=max(max(s2.k[0],s2.k[1]),s2.k[2]);
	if(s1max!=s2max) return s1max>s2max;
	else return same_1(s1,s2);
}
inline void solve(){
	scanf("%d",&n);
	N=n/2; 
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&p[i].a[0],&p[i].a[1],&p[i].a[2]);
		p[i].k[0]=p[i].a[0]-max(p[i].a[1],p[i].a[2]);
		p[i].k[1]=p[i].a[1]-max(p[i].a[0],p[i].a[2]);
		p[i].k[2]=p[i].a[2]-max(p[i].a[0],p[i].a[1]);
	}
	sort(p,p+n,cmp);
	ans=c[0]=c[1]=c[2]=0;
	for(int i=0;i<n;i++){
		if(c[0]==N){
			for(int j=i;j<n;j++){
				if(p[j].a[1]>p[j].a[2]) ans+=p[j].a[1];
				else ans+=p[j].a[2];
			}
			break;
		}
		else if(c[1]==N){
			for(int j=i;j<n;j++){
				if(p[j].a[0]>p[j].a[2]) ans+=p[j].a[0];
				else ans+=p[j].a[2];
			}
			break;
		}
		else if(c[2]==N){
			for(int j=i;j<n;j++){
				if(p[j].a[1]>p[j].a[0]) ans+=p[j].a[1];
				else ans+=p[j].a[0];
			}
			break;
		}
		else{
			if(p[i].a[0]>p[i].a[1]&&p[i].a[0]>p[i].a[2]) ans+=p[i].a[0],c[0]++;
			else if(p[i].a[1]>p[i].a[2]) ans+=p[i].a[1],c[1]++;
			else ans+=p[i].a[2],c[2]++;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
