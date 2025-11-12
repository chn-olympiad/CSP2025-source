#include<bits/stdc++.h>
using namespace std;
int seat[4004][4004];
int fs[505];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,num;
	cin>>m>>n;
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		cin>>fs[i];
	}
	num=fs[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m-1;j++){
			if(fs[j]<fs[j+1]) swap(fs[j],fs[j+1]);
			if(fs[j]==num) cnt=j;
		}
	}
	int ans=cnt/m;
	if(cnt%m==0&&ans%2==0) cout<<ans<<" "<<1;
	else if(cnt%m==0&&ans%2!=0) cout<<ans<<" "<<m;
	else{
		if(ans%2==0) cout<<ans+1<<" "<<cnt%m;
		else cout<<ans+1<<" "<<m-(cnt%m)+1;
	}
	return 0;
} 
