#include<bits/stdc++.h>
using namespace std;
int t,n,cn1,cn2,cn3,st1[100005],st2[100005],st3[100005],lp[100005];
long long ans;
struct op{
	int a,b,c;
}p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cn1=0,cn2=0,cn3=0,ans=0;
		for(int i=1;i<=n;i++)cin>>p[i].a>>p[i].b>>p[i].c;
		for(int i=1;i<=n;i++){
			if(p[i].a>=max(p[i].b,p[i].c))st1[++cn1]=i,ans+=p[i].a;
			else if(p[i].b>=max(p[i].a,p[i].c))st2[++cn2]=i,ans+=p[i].b;
			else st3[++cn3]=i,ans+=p[i].c;
		}
		if(cn1>n/2){
			for(int i=1;i<=cn1;i++)lp[i]=min(p[st1[i]].a-p[st1[i]].b,p[st1[i]].a-p[st1[i]].c);
			sort(lp+1,lp+cn1+1);
			for(int i=1;i<=cn1-n/2;i++)ans-=lp[i];
		}else if(cn2>n/2){
			for(int i=1;i<=cn2;i++)lp[i]=min(p[st2[i]].b-p[st2[i]].a,p[st2[i]].b-p[st2[i]].c);
			sort(lp+1,lp+cn2+1);
			for(int i=1;i<=cn2-n/2;i++)ans-=lp[i];
		}else{
			for(int i=1;i<=cn3;i++)lp[i]=min(p[st3[i]].c-p[st3[i]].b,p[st3[i]].c-p[st3[i]].a);
			sort(lp+1,lp+cn3+1);
			for(int i=1;i<=cn3-n/2;i++)ans-=lp[i];
		}
		for(int i=1;i<=n;i++)lp[i]=0;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
