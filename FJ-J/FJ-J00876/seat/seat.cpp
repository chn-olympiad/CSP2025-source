#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	int sco[110]={0};
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>sco[i];
	}
	r=sco[1];
	sort(sco+1,sco+n*m+1,cmp);
	int index;
	for(int i=1;i<=n*m;++i){
		cout<<sco[i]<<" ";
		if(sco[i]==r)index=i;
	}
	cout<<endl;
	if((index/n+1)%2==0){
		if(index%n==0)cout<<(index/n)<<" "<<n-(index%n)+1;
		else cout<<(index/n+1)<<" "<<n-(index%n)+1;
	}
	else{
		if(index%n==0)cout<<(index/n)<<" "<<(index%n);
		else cout<<(index/n+1)<<" "<<(index%n);
	}
	
	return 0;
}