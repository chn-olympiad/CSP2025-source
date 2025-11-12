#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	int num;
	int p;
}e[105];
bool cmp(st q,st p){
	return q.num>p.num;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>e[i].num;
		e[i].p=i; 
	}
	sort(e+1,e+n*m+1,cmp);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(e[i].p==1){
			ans=i;
			break;
		}
	}
	int w;
	if(ans%n==0){
		w=ans/n;
	}
	else{
		w=ans/n+1;
	}
	int b=ans%n;
	if(w%2==0){
		if(b==0) cout<<w<<" "<<1;
		else cout<<w<<" "<<n-b+1;
	}
	else{
		if(b==0) cout<<w<<" "<<n;
		else cout<<w<<" "<<b;
	}
	return 0;
} 