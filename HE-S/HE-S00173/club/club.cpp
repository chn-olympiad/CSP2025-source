#include<bits/stdc++.h>
using namespace std;
const int MN=1e5+10;
int T,n,s,t[5];
struct Node{
	int v[5];
}p[MN];
bool cmpa(Node x,Node y){
	return x.v[1]>x.v[1];
}
void f(int x,int k){
	if(x>n){
		s=max(s,k);
		return;
	}
	for(int i=1;i<=3;++i){
		if(t[i]>=n/2)continue;
		++t[i];
		f(x+1,k+p[x].v[i]);
		--t[i];
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n;
		s=0,t[1]=0,t[2]=0,t[3]=0;
		int b=0,c=0;
		for(int i=1;i<=n;++i){
			cin>>p[i].v[1]>>p[i].v[2]>>p[i].v[3];
			if(!b&&p[i].v[2])b=1;
			if(!c&&p[i].v[3])c=1;
		}
		if(!c&&!b){
			sort(p+1,p+1+n,cmpa);
			for(int i=1;i<=n/2;++i)s+=p[i].v[1];
			cout<<s<<'\n';
			continue;
		}
		f(1,0);
		cout<<s<<'\n';
	}
	return 0;
}
