#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,a,b,c;
struct node{
	int a,b,c;
};
node nlis[N];
long long ans,tans;

bool func(node a,node b){
	int t1=max(max(a.a,a.b),a.c)-min(min(a.a,a.b),a.c);
	int t2=max(max(b.a,b.b),b.c)-min(min(b.a,b.b),b.c);
	return t1>=t2;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=0,a=0,b=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>nlis[i].a>>nlis[i].b>>nlis[i].c;
		sort(nlis+1,nlis+1+n,func);
		for(int i=1;i<=n;i++){
			int mx=max(max(nlis[i].a,nlis[i].b),nlis[i].c);
			if(mx==nlis[i].a){
				if(a<n/2){
					ans+=nlis[i].a;
					a++;
				}
				else{
					if(nlis[i].b>=nlis[i].c and b<n/2) ans+=nlis[i].b,b++;
					else ans+=nlis[i].c,c++;
				}
			}
			else if(mx==nlis[i].b){
				if(b<n/2){
					ans+=nlis[i].b;
					b++;
				}
				else{
					if(nlis[i].a>=nlis[i].c and a<n/2) ans+=nlis[i].a,a++;
					else ans+=nlis[i].c,c++;
				}
			}
			else{
				if(c<n/2){
					ans+=nlis[i].c;
					c++;
				}
				else{
					if(nlis[i].b>=nlis[i].a and b<n/2) ans+=nlis[i].b,b++;
					else ans+=nlis[i].a,a++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
