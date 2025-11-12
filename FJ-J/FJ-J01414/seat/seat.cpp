#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000],ans=0,cnt=0;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
	if(i==1){
		ans=a[i];
	}
}
for(int i=1;i<=n*m;i++){
	while(a[i]>ans){
	cnt++;	
	}
}
if(cnt%n==0&&cnt/n%2==1){
	cout<<cnt/n<<" "<<n;
}
if(cnt%n==0&&cnt/n%2==0){
	cout<<cnt/n<<" "<<1;
}
if(cnt%n!=0&&cnt/n%2==1){
	cout<<cnt/n+1<<" "<<n+1-cnt%n;
}
if(cnt%n!=0&&cnt/n%2==0){
	cout<<cnt/n+1<<" "<<cnt%n;
}
	return 0;
}
