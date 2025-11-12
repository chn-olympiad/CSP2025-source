#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct st{
	int k,id;
}s[100001];
bool cmp(st x,st y){
	return x.k>y.k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].k;
		s[i].id=i;
	}
	sort(s+1,s+1+n*m,cmp);
	int ns=0;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				ns++;
				if(s[ns].id==1){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				ns++;
				if(s[ns].id==1){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
