#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
int n,m,k,cnt=1,tem=1;
lint ans=0;
bool v1=true;
struct node{
	lint u,v,w;
};
node s[10005];
node q[10005];
lint c[10005];
bool vl[10005];
bool cmp(node x,node y){
	return x.w<y.w;
}
void f1(){
	sort(s+1,s+tem,cmp);
	//cout<<s[1].u;
	//cout<<tem<<" ";
	vl[s[1].u]=true;
	for(int i=1;i<=tem;i++){
		if(!vl[s[i].v]){
			vl[s[i].v]=true;
		//	cout<<s[i].w<<" ";
			ans+=s[i].w;
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[tem].u>>s[tem].v>>s[tem].w;
		tem++;
	}
	for(int i=1;i<=m;i++){
		s[tem].u=s[i].v;
		s[tem].v=s[i].u;
		s[tem].w=s[i].w;
		tem++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) v1=false;
		for(int j=1;j<=n;j++){
			q[cnt].u=i;
			q[cnt].v=j;
			cin>>q[cnt].w;
			cnt++;
		}
	}
	if(k==0) f1();
	else if(v1){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				if(i!=j){
					s[tem].u=q[i].v;
					s[tem].v=q[j].v;
					s[tem].w=q[i].w+q[j].w;
					tem++;
				}
			}	
		}
		f1();
	}
	return 0;
}
