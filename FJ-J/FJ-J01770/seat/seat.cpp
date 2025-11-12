#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int xia=0;
	for(int i=1;i<=n*m;++i){
		cin>>s[i];
		if(i==1) xia=s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(s[i]==xia){
			cout<<(i-1)/n+1<<" ";
			if(((i-1)/n+1)%2==0) cout<<(n+1)-((i-1)%n+1);
			else cout<<(i-1)%n+1;
			break;
		}
		else continue;
	}
	return 0;
}
