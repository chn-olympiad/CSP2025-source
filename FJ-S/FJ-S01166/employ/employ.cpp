#include<bits/stdc++.h>
#define maxn 550
using namespace std;
int a[maxn],c[maxn];
int n,m,ans;
bool f=false;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	 	if(!a[i]) f=true;
	}
	for(int i=1;i<=n;++i) cin>>c[i];
	if(!f) printf("0");
	sort(c+1,c+n+1);
	return 0;
}
