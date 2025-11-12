#include<bits/stdc++.h>
using namespace std;
long long b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>b[i];
	}
	int ai=b[1];
	sort(b+1,b+n*m+1);
	for(int i=n*m,j=1;i>=1;--i,++j){
		if(b[i]==ai){
			ai=j;
			break;
		}
	}
	if(m==1){
		cout<<1<<' '<<ai;
		return 0;
	}
	if(ai%n==0){
		cout<<ai/n<<' ';
	}else{
		cout<<ai/n+1<<' ';
	}
	if((ai/n)%2!=0){
		if(ai/n==1){
			cout<<m;
			return 0;
		}
		cout<<m-(ai%n)+1;
		return 0;
	}else{
		if(ai/n==1){
			cout<<1;
			return 0;
		}
		cout<<m-((ai/n)%n);
		return 0;
	}
	return 0;
}
