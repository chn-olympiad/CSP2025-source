#include<bits/stdc++.h>
using namespace std;
int n,f,s,t;
struct node{
	int a,b,c;
}r[100005];
long long ans,an;
int cmp (node x,node y){
	return max(max(x.a,x.b),x.c)>max(max(y.a,y.c),y.b);
}
void dfs(int num){
	if(num>n){
		ans=max(ans,an);
		return ;
	}
	if(f>0){
		an+=r[num].a;
		f--;
		dfs(num+1);
		f++;
		an-=r[num].a;
	}
	if(s>0){
		an+=r[num].b;
		s--;
		dfs(num+1);
		s++;
		an-=r[num].b;
	}
	if(t>0){
		an+=r[num].c;
		t--;
		dfs(num+1);
		t++;
		an-=r[num].c;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		bool flagA=1;
		ans=0,an=0;
		cin>>n;
		f=n/2;
		s=n/2;
		t=n/2;
		for(int i=1;i<=n;i++){
			cin>>r[i].a>>r[i].b>>r[i].c;
			if(r[i].b!=r[i].c||r[i].b!=0)flagA=0;
		}
		if(flagA){
			sort(r+1,r+n+1,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=r[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1);
		cout<<ans<<'\n';
		
	}
}
//用我朋友20寿命换我这题能过 
