#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int a[N],b[N],c[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int res=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		int d=n/3;
		int h=n%3;
		for(int i=0;i<d;i++){
			res+=a[i]+b[i]+c[i];
		}
		int f=0,s=0;
		f=max(a[d],b[d]);
		f=max(f,c[d]);
		s=max(a[d],b[d]);
		s=min(s,c[d]);
		if(h==1){
			res+=f;
		}else{
			res+=f+s;
		}
		cout<<f<<s;
		printf("%d\n",res);
	}
	return 0;
}
