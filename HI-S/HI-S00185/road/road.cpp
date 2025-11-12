#include<bits/stdc++.h>
using namespace std;
int n,m,k,minn = 1e9;
bool b[1000005];
struct node{
	int st,en,mon;
}a[1000005];
void f(int now,int cnt){
	cout<<now<<endl;
	b[now] = 1;
	bool flag = 1;
	for(int i = 1;i<=n;i++){
		if(b[i]==0){
			flag = 0;
			break;
		}
	} 
	if(flag){
		if(cnt<minn){
			minn = cnt;
		}
		b[now]  =0;
		return;
	}
	for(int i = 1;i<=m;i++){
		if(a[i].st==now&&b[a[i].en]==0){
			f(a[i].en,cnt+a[i].mon);
			
		} 
	}
	b[now] = 0;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>a[i].st>>a[i].en>>a[i].mon;
	}
	f(1,0);
	cout<<minn;
	return 0;
}
