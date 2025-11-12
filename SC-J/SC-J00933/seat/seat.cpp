#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],b[105],mingci,tong[105],xiab,lie,hang;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		tong[a[i]]++;
	}
	for(int i=100;i>=1;i--){
		if(tong[i]>=1){
			while(tong[i]--) b[++xiab]=i;
		} 
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==a[1]){
			mingci=i;
			break;
		}
	}
	lie=(mingci-1)/n+1;
	if(lie%2==0) hang=n+1-mingci%n;
	else if(mingci<=n) hang=mingci;
	else hang=mingci%n;
	cout<<lie<<" "<<hang;
	fclose("seat.in");
	fclose("seat.out");
	return 0;
}