#include <bits/stdc++.h>
using namespace std;
#define int long long
struct aaaa{
	int b,e;
}l[500005];
int a[500005],f[500005],g[500005];
int yor(int x,int y){
	if(x==0||y==0){
		return max(x,y);
	}int p,q,w[25],s=0;
	for(int i=19;i>=0;i--){
		int t=pow(2,i);
		if(x>=t){
			p=1;
			x-=t;
		}else{
			p=0;
		}if(y>=t){
			q=1;
			y-=t;
		}else{
			q=0;
		}if(p==q){
			w[i]=0;
		}else{
			w[i]=1;
		}
	}for(int i=19;i>=0;i--){
		s+=w[i]*pow(2,i);
	}return s;
}bool t1(aaaa x,aaaa y){
	return x.b<y.b;
}bool t2(aaaa x,aaaa y){
	return x.e<y.e;
}signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=yor(f[i-1],a[i]);
		g[i]=yor(f[i],a[i]);
		for(int j=1;j<=i;j++){
			if(yor(f[i],g[j])==k){
				l[t].b=j;
				l[t].e=i;
				t++;
			}
		}
	}sort(l,l+t,t1);
	sort(l,l+t,t2);
	int s=1,e=l[0].e;
	for(int i=1;i<t;i++){
		if(l[i].b>e){
			e=l[i].e;
			s++;
		}
	}cout<<s;
	return 0;
}
