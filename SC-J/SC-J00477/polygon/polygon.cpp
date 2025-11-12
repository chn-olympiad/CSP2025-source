#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool b[5005];
int MO=998244353;
int n=0;
int ci=0;
void sf(int i,int m,int c,int ma){
	if(i>n){
		return;
	}
	if(m>=3 && ma*2<c){
		ci++;
		ci%=MO;
	}
	for(int j=i+1;j<=n;j++){
		if(b[j])continue;
		b[j]=1;
		sf(j,m+1,c+a[j],max(ma,a[j]));
		b[j]=0;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=0;
	}
	sf(0,0,0,0);
	cout<<ci;
	return 0;
}