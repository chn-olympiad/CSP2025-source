#include <bits/stdc++.h>
using namespace std;
const int maxn=100003;
int n;
struct node{
	int h[3],c;
	int hope[3],cha[3];
}a[maxn];
bool cmp(node p,node q){
	if(max(p.h[0],max(p.h[1],p.h[2]))!=max(q.h[0],max(q.h[1],q.h[2])))
		return max(p.h[0],max(p.h[1],p.h[2]))>max(q.h[0],max(q.h[1],q.h[2]));
	if(p.h[0]!=q.h[0])return p.h[0]>q.h[0];
	if(p.h[1]!=q.h[1])return p.h[1]>q.h[1];
	return p.h[2]>q.h[2];
}
int main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans=0,ans1=0,b[3];
	while(t--){
		cin>>n;
		int maxx=0,mx=0,minn=20000000,ix=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].h[0]>>a[i].h[1]>>a[i].h[2];
			maxx=a[i].h[0],mx=0,minn=a[i].h[0],ix=0;
			for(int j=1;j<3;j++){
				if(a[i].h[j]>maxx)mx=j,maxx=a[i].h[j];
				if(a[i].h[j]<minn)ix=j,minn=a[i].h[j];
			}
			if(mx==ix)a[i].hope[0]=0,a[i].hope[1]=1,a[i].hope[2]=2;
			else{
				a[i].hope[0]=mx,
				a[i].hope[2]=ix;
				a[i].hope[1]=0;
				if(a[i].hope[1]==mx||a[i].hope[1]==ix)a[i].hope[1]++;
				if(a[i].hope[1]==mx||a[i].hope[1]==ix)a[i].hope[1]++;
			}
		}
		
		sort(a+1,a+1+n,cmp);
		b[1]=0,b[2]=0,b[0]=0,ans=0;
		for(int i=1;i<=n;i++){
			if(b[a[i].hope[0]]<n/2){
				b[a[i].hope[0]]++;
				ans+=a[i].h[a[i].hope[0]];
				a[i].c=0;
			}else if(b[a[i].hope[1]]<n/2){
				b[a[i].hope[1]]++;
				ans+=a[i].h[a[i].hope[1]];
				a[i].c=1;
			}else if(b[a[i].hope[2]]<n/2){
				b[a[i].hope[2]]++;
				ans+=a[i].h[a[i].hope[2]];
				a[i].c=2;
			}
		}
		b[1]=0,b[2]=0,b[0]=0,ans1=0;
		for(int i=n;i>=1;i--){
			if(b[a[i].hope[0]]<n/2){
				b[a[i].hope[0]]++;
				ans1+=a[i].h[a[i].hope[0]];
				a[i].c=0;
			}else if(b[a[i].hope[1]]<n/2){
				b[a[i].hope[1]]++;
				ans1+=a[i].h[a[i].hope[1]];
				a[i].c=1;
			}else if(b[a[i].hope[2]]<n/2){
				b[a[i].hope[2]]++;
				ans1+=a[i].h[a[i].hope[2]];
				a[i].c=2;
			}
		}
		cout<<max(ans,ans1)<<endl;
	}
	return 0;
}
