#include<bits/stdc++.h>
using namespace std;
int n,m,st[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>st[i];
	}
	int w=st[1];
	sort(st+1,st+1+n*m,cmp);
	int o=0;
	for(int i=1;i<=n*m;i++){
		if(st[i]==w){
			o=i;
			break;
		}
	}
	int q,e;
	q=o/n;
	e=o%n;
	if(e) q++;
	cout<<q;
	if(q%2==0){
		if(e==0) cout<<' '<<1;
		else cout<<' '<<n+1-e;
	}
	else {
		if(e==0) cout<<' '<<n;
		else cout<<' '<<e;
	}
	return 0;
}
