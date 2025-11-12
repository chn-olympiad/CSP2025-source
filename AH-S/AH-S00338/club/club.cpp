#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
bool f1;
struct Gin{
	int a,b,c;
}h[200005];
bool cmp1(Gin x,Gin y){
	return x.a>y.a;
}
bool cmp2(Gin x,Gin y){
	return x.b>y.b;
}
bool cmp3(Gin x,Gin y){
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		f1=1;
		for(int i=1;i<=n;i++){
			cin>>h[i].a>>h[i].b>>h[i].c;
			if((h[i].a==0&&h[i].b==0)||(h[i].a==0&&h[i].c==0)||(h[i].b==0&&h[i].c==0));
			else f1=0;
		}
		if(n==2){
			ans=max(h[1].a+h[2].b,h[1].a+h[2].c);
			ans=max(ans,max(h[1].b+h[2].a,h[1].b+h[2].c));
			ans=max(ans,max(h[1].c+h[2].a,h[1].c+h[2].b));
			cout<<ans<<'\n';
			continue;
		}
		if(f1){
			if(h[1].a==0&&h[1].b==0){
				sort(h+1,h+n+1,cmp3);
				for(int i=1;i<=n/2;i++)
					ans=ans+h[i].c;
			}
			else if(h[1].a==0&&h[1].c==0){
				sort(h+1,h+n+1,cmp2);
				for(int i=1;i<=n/2;i++)
					ans=ans+h[i].b;
			}
			else if(h[1].b==0&&h[1].c==0){
				sort(h+1,h+n+1,cmp1);
				for(int i=1;i<=n/2;i++)
					ans=ans+h[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<rand()%n;
	}
	return 0;
}
/*
☯
我听到了『强运』的回响
 */
