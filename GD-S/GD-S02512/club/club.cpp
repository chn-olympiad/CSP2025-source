#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct E{
	int a,b,c;
};
E e[N];
int a,b;
bool cmp(E A,E B){
	a=max(A.a,max(A.b,A.c));
	b=max(B.a,max(B.b,B.c));
	return a>b;
}
bool na(E A,E B){
	a=max(A.b,A.c);
	b=max(B.b,B.c);
	return a>b;
}
bool nb(E A,E B){
	a=max(A.a,A.c);
	b=max(B.a,B.c);
	return a>b;
}
bool nc(E A,E B){
	a=max(A.b,A.a);
	b=max(B.b,B.a);
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,nn;
	cin>>t;
	while(t--){
		int ca=0,cb=0,cc=0,cnt=1,_=0;long long ans=0;
		cin>>n;
		nn=(n>>1);
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
		}
		sort(e+1,e+n+1,cmp);
		cnt=1;
		while(1){
			if(e[cnt].a>e[cnt].b&&e[cnt].a>e[cnt].c){
				ca++;_=e[cnt].a;
			}else if(e[cnt].b>e[cnt].c){
				cb++;_=e[cnt].b;
			}else{
				cc++;_=e[cnt].c;
			}
			if(cnt==n){
				ans+=_;break;
			}
			if(ca>nn||cb>nn||cc>nn)break;
			ans+=_;
			cnt++;
		}
		if(cnt==n){
			cout<<ans<<"\n";
			continue;
		}
		if(ca>nn){
			sort(e+cnt,e+n+1,na);
			for(int i=cnt;i<=n;i++){
				ans+=((e[i].b>e[i].c) ? e[i].b :e[i].c);
			}
		}
		else if(cb>nn){
			sort(e+cnt,e+n+1,nb);
			for(int i=cnt;i<=n;i++){
				ans+=((e[i].a>e[i].c) ? e[i].a :e[i].c);
			}
		}
		else{
			sort(e+cnt,e+n+1,nc);
			for(int i=cnt;i<=n;i++){
				ans+=((e[i].b>e[i].a) ? e[i].b :e[i].a);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

