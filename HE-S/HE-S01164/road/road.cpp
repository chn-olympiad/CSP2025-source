#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[100005];
bool cmp(node a,node b){
	return a.w<b.w;
}
string s_ch="";
int ans_ch=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(s_ch.find(to_string(a[i].u)+to_string(a[i].v))){
			ans_ch+=a[i].w;
			s_ch+=to_string(a[i].u)+to_string(a[i].v)+'0';
		}
	}
	cout<<ans_ch;
	return 0;
}
