#include <bits/stdc++.h>
using namespace std;
struct S{
	int a,b,c;
}p[100005];
bool cmp(S x,S y){
	if(x.a!=y.a)return x.a>y.a;
	if(x.b!=y.b)return x.b>y.b;
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxnb=-1,maxnc=-1;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			maxnb=max(maxnb,p[i].b);
			maxnc=max(maxnc,p[i].c);
			
		}
		if(n==2){
			cout<<max(p[1].a+p[2].b,max(p[1].b+p[2].a,max(p[1].a+p[2].c,max(p[1].c+p[2].a,max(p[1].c+p[2].b,p[1].b+p[2].c)))))<<endl;
			continue;
		}
		if(maxnc==0){
			if(maxnb==0){
				int cnt=0;
				sort(p+1,p+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					cnt+=p[i].a;
				}
				cout<<cnt<<endl;
				continue;
			}else{
				cout<<(n/2)*maxnb<<endl;
			}
		}else{
			cout<<(n/2)*maxnc<<endl;
		}
	} 
	
	return 0;
} 
