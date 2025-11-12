#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,f[N],s=0,ans=0;
struct aa{
	int a,b,c;
}p[N];
int cmp(aa x,aa y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].b==0 && p[i].c==0)s++;
		}	
		if(s==n){
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=p[i].a;
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
