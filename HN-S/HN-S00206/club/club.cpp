#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,sum;
struct node{
	int a,b,c,v;
}s[N];
bool cmp(node o,node p){
	return o.v>p.v;
}
void fun(int g,int x,int y,int z,int l){
	if(g>=n){
		l=max(l,sum);
		return;
	}
	else if(x<=n/2){
		fun(g++,x++,y,z,l+s[g+1].v);
	}
	else if(y<=n/2){
		fun(g++,x,y++,z,l+s[g+1].v);
	}
	else if(z<=n/2){
		fun(g++,x,y,z++,l+s[g+1].v);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		sum=0;
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			s[i].v=max(s[i].a,max(s[i].b,s[i].c));
		}
		if(n<=10){
		fun(0,0,0,0,0);
		}
		else{
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sum=sum+s[i].v;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
