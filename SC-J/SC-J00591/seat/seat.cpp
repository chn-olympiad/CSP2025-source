#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,grade;
	cin>>n>>m;
	int a[101];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0) grade=a[0];
	}
	sort(a,a+n*m);
	int cnt=0;
	for(int i=0;i<=n*m;i++){
		if(a[i]==grade) cnt=i+1;
	}
	int x=cnt;
	cnt=n*m+1-x;
	for(int i=0;i<=cnt;i++){
		int b=cnt/n;
		cnt%=n;
		if(cnt==0){
			if(b%2==1) cout<<b<<" "<<n;
			else cout<<b<<" "<<1;
			return 0;
		}else{
			b++;
			if(b%2==1){
				cout<<b<<" "<<cnt;
				return 0;
			}else{
				cout<<b<<" "<<n+1-cnt;
				return 0;
			}
		}
	}
	return 0;
}