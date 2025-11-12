#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar();if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}

ll T,n,k,ans,cnt[5],s;
bool f[100010];
struct node{
	ll vn,pos,id;
};
node a[300010];

bool cmp(node x,node y){
	return x.vn>y.vn;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){ 
		bool A=true,B=true;
		read(n);
		for(int i=1;i<=n;i++){
			f[i]=0;
		}
		k=0,cnt[1]=0,cnt[2]=0,cnt[3]=0,ans=0,s=0;
		for(int i=1;i<=n;i++){
			read(a[++k].vn); a[k].pos=1; a[k].id=i; 
			read(a[++k].vn); a[k].pos=2; a[k].id=i; if(a[k].vn!=0) A=false;
			read(a[++k].vn); a[k].pos=3; a[k].id=i; if(a[k].vn!=0) B=false;
		}
		if(n==2){
			ll e=max(a[1].vn+a[5].vn,a[1].vn+a[6].vn);
			ll b=max(a[2].vn+a[4].vn,a[2].vn+a[6].vn);
			ll c=max(a[3].vn+a[4].vn,a[3].vn+a[5].vn);
			cout<<max(e,max(c,b));
			continue;
		}
		if(A&&B){
			sort(a+1,a+1+k,cmp);
			for(int i=1;i<=n/2;i++) s+=a[i].vn;
			cout<<s;
			continue;
		}
		if(B){
			for(int i=1;i<=k;i++) s+=a[i].vn;
			cout<<s;
			continue;
		}
		sort(a+1,a+1+k,cmp);
		for(int i=1;i<=k;i++){
			if(f[a[i].id]) continue;
			if(cnt[a[i].pos]>=n/2) continue;
			ans+=a[i].vn;
			cnt[a[i].pos]++;
			f[a[i].id]=true;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//5
//8 
//1 2 0
//3 4 0
//5 6 0
//7 8 0
//1 1 0
//1 1 0
//2 2 0
//3 3 0
//4 4 0


