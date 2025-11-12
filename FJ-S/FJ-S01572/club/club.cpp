#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n;
struct{
	int a,b,c;
}p[N];
void solveA(){
	int d=n/2;
	int ans=0;
	for(int i=1;i<=d;i++){
		int m=0,mi=0;
		for(int j=1;j<=n;j++){
		    if(p[j].a>m){
			    m=p[j].a;
			    mi=j;
		    }
		}
		ans+=m;
		p[mi].a=-1;
	}
	printf("%d",ans);
	return ;
}
void solve(){
	cin>>n;
	int max2=0,max3=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		max2=max(max2,p[i].b);
		max3=max(max3,p[i].c);
	}
	if(max2==0&&max3==0){
		solveA();
		return ;
	}else if(max3==0){
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
	    solve();	
	}
	return 0;
}
