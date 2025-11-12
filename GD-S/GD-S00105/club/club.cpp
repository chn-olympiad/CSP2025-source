#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+10;
struct st{
	long long a,b,c,f;
}p[maxn];
long long n,ans,b[10],x,maxb,maxc;
st w[maxn];
bool cmpa(st a,st b){
	return a.a<b.a;
}
bool cmpb(st a,st b){
	return a.b<b.b;
}
bool cmpc(st a,st b){
	return a.c<b.c;
}
void solve1(){
	sort(p+1,p+n+1,cmpa);
	for(int i=n;i>n/2;i--){
		ans+=p[i].a;
		//cout<<p[i].a;
	}
	cout<<ans;
}
void solve2(){
	sort(w+1,w+n+1,cmpa);
	long long sum=0;
	for(int i=1;i<=n;i++){
		w[i].a=p[i].a,w[i].b=p[i].b;
	}
	for(int i=n;i>n/2;i--){
		sum+=w[i].a;
		w[i].a=0,w[i].b=0;
	}
	sort(w+1,w+n+1,cmpb);
	for(int i=n;i>n/2;i--){
		sum+=w[i].b;
		//cout<<p[i].a;
	}
	ans=max(ans,sum);
	sum=0;
	sort(p+1,p+n+1,cmpa);
	for(int i=n;i>n/2;i--){
		sum=p[i].a;
		//cout<<p[i].a;
	}
	sort(p+1,p+n+1,cmpb);
	for(int i=n;i>n/2;i--){
		sum+=p[i].b;
		//cout<<p[i].a;
	}
	ans=max(sum,ans);
	cout<<ans;
}
void solve(){
	ans=0;
	cin>>n;
	x=n/2;
	for(int i=1;i<=n;i++){
		//cout<<"QAQ";
		cin>>p[i].a>>p[i].b>>p[i].c;
		maxb=max(maxb,p[i].b);
		maxc=max(maxc,p[i].c);
		long long t=max(p[i].c,max(p[i].a,p[i].b));
		if(t==p[i].a)b[1]++,p[i].f=1;
		else if(t==p[i].b)b[2]++,p[i].f=2;
		else b[3]++,p[i].f=3;
		//cout<<" "<<p[i].f;
	}
	//cout<<"qaq"<<endl;
	if(maxc==0&&maxb==0){
		solve1();
		return ;
	}
	for(int i=1;i<=3;i++){
		if(b[i]>x){
			if(i==1)sort(p+1,p+n+1,cmpa);
			else if(i==2)sort(p+1,p+n+1,cmpb);
			else sort(p+1,p+n+1,cmpc);
			long long pos=1;
			while(b[i]>x){
				//cout<<"QAQ";
				if(p[pos].f!=i){
					pos++;
					//cout<<"qq";
					continue;
				}
				long long maxp=0,p2=i,p3=0;
				for(int j=1;j<=3;j++){
					if(j==i)continue;
					if(j==1)maxp=max(maxp,p[pos].a);
					else if(j==2)maxp=max(maxp,p[pos].b);
					else maxp=max(maxp,p[pos].c);
				}//找第2 
				for(int j=1;j<=3;j++){
					if(j==i||p2!=i)continue;
					if(j==1&&maxp==p[pos].a){
						p2=j;
						if(i==2)p3=3;
						else p3=2; 
					}
					else if(j==2&&maxp==p[pos].b){
						p2=j;
						if(i==1)p3=3;
						else p3=1;
					}
					else if(j==3&&maxp==p[pos].c){
						p2=j;
						if(i==1)p3=2;
						else p3=1;
					}
				}//认第2 3
				if(b[p2]<x){
					b[i]--;
					b[p2]++;
					p[pos].f=p2;
				}else{
					b[i]--;
					b[p3]++;
					p[pos].f=p3;
				}
				//移位 
				pos++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i].f==1)ans+=p[i].a;
		else if(p[i].f==2)ans+=p[i].b;
		else ans+=p[i].c;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
