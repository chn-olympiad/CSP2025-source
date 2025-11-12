#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005],b[100005],c[100005];
long long ans=0;
long long maxx(long long x,long long y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}
struct student{
	int a,b,c;
}h[100005];
void dfs(int suma,int sumb,int sumc,int nowa,int nowb,int nowc,int i){
	if(suma>n/2||sumb>n/2||sumc>n/2){
		return;
	}
	else if(i>n){
		long long sum=nowa+nowb+nowc;
		ans=maxx(ans,sum);
		return;
	}
	else{
		dfs(suma+1,sumb,sumc,nowa+a[i],nowb,nowc,i+1);
		dfs(suma,sumb+1,sumc,nowa,nowb+b[i],nowc,i+1);
		dfs(suma,sumb,sumc+1,nowa,nowb,nowc+c[i],i+1);
	}
	return;
}
bool cmp(student x,student y){
	return x.a>y.a;
}
int main(){
	ifstream read("club.in");
	ofstream write("club.out");
	read>>t;
	while(t--){
		read>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ans=0;
		bool ba=0;
		for(int i=1;i<=n;i++){
			read>>h[i].a>>h[i].b>>h[i].c;
			if(h[i].b!=0||h[i].c!=0){
				ba=1;
			}
		}
		if(!ba){
			sort(h+1,h+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=h[i].a;
			}
			write<<ans;
		}
		else{
			dfs(0,0,0,0,0,0,0);
			write<<ans<<endl;
		}
	}
	return 0;
} 
