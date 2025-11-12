#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b,cnt = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 1;i < n*m;i++){
		cin>>b;
		if(b>a)cnt++;
	}
	if(((cnt-1)/n)%2==0){
		cout<<(cnt-1)/n+1<<" "<<(cnt-1)%n+1;
	}else{
		cout<<(cnt-1)/n+1<<" "<<n-((cnt-1)%n);
	}
	return 0;
}
