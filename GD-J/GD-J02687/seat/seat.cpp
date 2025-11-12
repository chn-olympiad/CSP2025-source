#include<bits/stdc++.h>
using namespace std;
const int MX=105;
int st[105],n,m;
int sx(int a){
	return (a-1)/n+1;
}
int sy(int a){
	if(sx(a)%2==1) return (a-1)%n+1;
	return n-(a-1)%n;
}
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(st,0,sizeof(st));
	cin>>n>>m;
	int g=1;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&st[i]);
		if(st[i]>st[1]){
			g++;
		}
	}//cout<<g<<" ";
/*	int R=st[1],Id;
	sort(st+1,st+n+1);
	for(int i=n*m;i>=0;i--){
		if(R==st[i]){
			Id=i;
			cout<<R<<" "<<Id<<endl;
			break;
		}
	}*/
	cout<<sx(g)<<" "<<sy(g);
	return 0;
}
