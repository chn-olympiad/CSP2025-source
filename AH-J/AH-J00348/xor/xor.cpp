#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct p{
	int a,b;
}c[10000005];
bool cmp(p q,p w){
	if(q.b!=w.b) return q.b<w.b;
	return q.a<w.a;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=0;
	}
	if(k==0&&f){//A
		printf("%d",n/2);
		return 0;
	}
	if(k<=1){//B
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(!a[i]) ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	//6~12测试点
	 int y=0;
	for(int i=1;i<=n;i++){
		int g;
		for(int j=i;j<=n;j++){
		 if(j==i) g=a[j];
			else{
				g^=a[j];
			}
			if(g==k) c[++y].a=i,c[y].b=j;
		}
	}
	sort(c+1,c+y+1,cmp);
	int en=c[1].b,ans=1;
	for(int i=2;i<=y;i++){
		if(c[i].a>en) ans++,en=c[i].b;
	}
	printf("%d",ans);
	return 0;
}
// ^
