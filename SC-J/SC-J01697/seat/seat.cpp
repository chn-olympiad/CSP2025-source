#include<bits/stdc++.h>
using namespace std;
int n,m;
struct st{
	int id;
	int score;
}a[15][15],s[250];
bool cmp(st x,st y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	for(int i=1;i<=(n*m);i++){
		cin>>s[i].score;
		s[i].id=i;
	}
	sort(s+1,s+(n*m)+1,cmp);
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
				a[i][j].score=s[++cnt].score;
				a[i][j].id=s[cnt].id;
			}
		}
		else if(j%2==0){
			for(int i=n;i>=1;i--){
				a[i][j].score=s[++cnt].score;
				a[i][j].id=s[cnt].id;
			}
		}
	}
	////////////////////
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j].score<<' ';
//		}
//		cout<<"\n";
//	}
	////////////////////
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j].id==1){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}