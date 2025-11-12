#include<bits/stdc++.h>
using namespace std;
int n,m;
int ll,c,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ll;
	for(int i=2;i<=n*m;i++){
		cin>>c;
		if(c>ll)cnt++;
	}
	if(cnt%(2*n)!=0&&cnt%(2*n)<=n){
		cout<<(cnt-1)/n+1<<" "<<((cnt+n-1)%n)+1;
	}else{
		cout<<(cnt-1)/n+1<<" "<<n-(cnt%n)+1;
	}
	return 0;
} 
