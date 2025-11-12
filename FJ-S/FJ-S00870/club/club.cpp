#include<bits/stdc++.h>
using namespace std;
int T;
struct Node{
	int a,b,c;
	int flag,maxv;
} v[100005];
bool cmp(Node x,Node y){
	if(x.maxv==y.maxv) {
		if(x.a==y.a){
			if(x.b==y.b) return x.c>y.c;
			return x.b>y.b;
		}
		return x.a>y.a;
	}
	return x.maxv>y.maxv;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;	
		for(int i=1;i<=n;i++){
			cin>>v[i].a>>v[i].b>>v[i].c;
			v[i].flag=0;
			v[i].maxv=max(v[i].a,max(v[i].b,v[i].c));
		}
		sort(v+1,v+1+n,cmp);
		if(n==2){
			int ans1=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					int q,p;
					if(i==j) continue;
					if(i==1) q=v[1].a;
					if(i==2) q=v[1].b;
					if(i==3) q=v[1].c;
					if(j==1) p=v[2].a;
					if(j==2) p=v[2].b;
					if(j==3) p=v[2].c;
					ans1=max(ans1,q+p);
				} 
			}
			cout<<ans1<<endl;
			continue;
		}
		int num1=0,num2=0,num3=0,ans=0,i1;
		for(int i=1;num1<=(n/2)&&num2<=(n/2)&&num3<=(n/2)&&i<=n;i++){
			if(v[i].maxv==v[i].a) num1++,ans+=v[i].a,v[i].flag=1;
			else if(v[i].maxv==v[i].b) num2++,ans+=v[i].b,v[i].flag=1;
			else if(v[i].maxv==v[i].c) num3++,ans+=v[i].c,v[i].flag=1;
			i1=i;
		}
		if(i1==n) {
			cout<<ans<<endl;
			continue;
		}
		for(int i=i1;i<=n;i++){
			if(v[i].maxv==v[i].a) ans+=max(v[i].b,v[i].c),v[i].b==v[i].c?(v[i].b<v[i].c?(num3++):(num2++)):(num2<num3?(num2++):(num3++)),v[i].flag=1;
			else if(v[i].maxv==v[i].b) ans+=max(v[i].a,v[i].c),v[i].a==v[i].c?(v[i].a<v[i].c?(num3++):(num1++)):(num1<num3?(num1++):(num3++)),v[i].flag=1;
			else if(v[i].maxv==v[i].c) ans+=max(v[i].b,v[i].c),v[i].b==v[i].a?(v[i].b<v[i].a?(num1++):(num2++)):(num2<num1?(num2++):(num1++)),v[i].flag=1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
