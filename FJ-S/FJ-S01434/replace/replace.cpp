#include <bits/stdc++.h>
using namespace std;
const int N=200005;

struct node{
	int a,b;
	int mi;
}po[N];
int n,q;
int dn[N],pt;
long long ans;
bool nouse(int x){
	for(int i=1 ; i<=pt ; i++){
		if(dn[i]==x) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string ta,tb;
	scanf("%d%d",&n,&q);
	for(int i=1 ; i<=n ; i++){
		cin>>ta>>tb;
		for(int j=0 ; ta[j]!='b' ; j++) po[i].a++;
		for(int j=0 ; tb[j]!='b' ; j++) po[i].b++;
		po[i].mi=po[i].a-po[i].b;
	}
	while(q--){
		int a=0,b=0;
		cin>>ta>>tb;
		for(int j=0 ; ta[j]!='b' ; j++) a++;
		for(int j=0 ; tb[j]!='b' ; j++) b++;
		for(int i=1 ; i<=n ; i++){
			if(po[i].mi==a-b && po[i].a<=a && nouse(po[i].a)) {
				ans++;
				dn[pt++]=po[i].a;
			}
		}
		printf("%lld\n",ans);
		ans=0;
		pt=1;
	}
	
	return 0;
}
