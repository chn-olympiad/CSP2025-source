#include <bits/stdc++.h>
using namespace std;
#define int long long
struct aaaa{
	int l,v;
}v[100005];
bool t2(aaaa x,aaaa y){
	return x.l<y.l;
}bool t1(aaaa x,aaaa y){
	return x.v>y.v;
}int n,ans,s[5],l[4],a,b,c;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int o=0;o<T;o++){
		cin>>n;
		ans=0,a=0,b=0,c=0,l[1]=0,l[2]=0;l[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			ans+=max(a,max(b,c));
			if(a>=max(b,c)){
				v[i].l=1;
				l[1]++;
				v[i].v=a-max(b,c);
			}else if(b>=max(a,c)){
				v[i].l=2;
				l[2]++;
				v[i].v=b-max(a,c);
			}else{
				v[i].l=3;
				l[3]++;
				v[i].v=c-max(a,b);
			}
		}sort(v+1,v+1+n,t2);
		if(l[1]>n/2){
			sort(v+1,v+1+l[1],t1);
			for(int j=n/2+1;j<=l[1];j++){
				ans-=v[j].v;
			}
		}else if(l[2]>n/2){
			sort(v+1+l[1],v+1+l[1]+l[2],t1);
			for(int j=l[1]+n/2+1;j<=l[1]+l[2];j++){
				ans-=v[j].v;
			}
		}else if(l[3]>n/2){
			sort(v+1+l[1]+l[2],v+1+n,t1);
			for(int j=l[1]+l[2]+n/2+1;j<=n;j++){
				ans-=v[j].v;
			}
		}s[o]=ans;
	}for(int i=0;i<T;i++){
		cout<<s[i]<<endl;
	}return 0;
}
