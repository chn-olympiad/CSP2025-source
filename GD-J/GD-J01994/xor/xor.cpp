#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sl;
struct node{
	int x,y;
}p[500005];
bool cmp(node xx,node yy){
	return xx.y<yy.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i]^a[i-1]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==m){
				p[++sl].x=i;
				p[sl].y=j;
			}
		}
	}
	sort(p+1,p+sl+1,cmp);
	int mb=p[1].y;
	for(int i=2;i<=sl;i++){
		if(p[i].x>mb){
			ans++;
			mb=p[i].y;
		}
	} 
	printf("%lld",ans+1);
	return 0;
}

