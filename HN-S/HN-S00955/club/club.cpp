#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
inline int read(){
	char ch=getchar();int x=0;bool f=false;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=true;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
	return x;
}
int t,n,a[N][4],maxn,maxf,m1,m2;
priority_queue<int , vector<int> ,greater<int> > q[4];

void work(int val,int pla){
	if(val>maxn) maxf=maxn,maxn=val,m2=m1,m1=pla;
	else if(val>maxf) maxf=val,m2=pla;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) a[i][j]=read();
		int ans=0;
		for(int i=1;i<=3;i++){
			while(q[i].size()) q[i].pop();
		}
		for(int i=1;i<=n;i++){
			maxn=maxf=m1=m2=0;
			work(a[i][1],1),work(a[i][2],2),work(a[i][3],3);
			ans+=maxn;
			//cout<<i<<" "<<maxn<<"\n";
			q[m1].push(maxn-maxf);
		}
		for(int i=1;i<=3;i++){
			int opt=q[i].size();
			if(opt>(n/2)){
				opt-=(n/2);
				for(int j=1;j<=opt;j++){
					int x=q[i].top();
					q[i].pop();
					ans-=x;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
