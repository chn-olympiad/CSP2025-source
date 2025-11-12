#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",cin);
	freopen("seat.out","w",cout);
	int n,m;
	cin>>n>>m;
	int f[n*m+1];
	int u=0;
	for(int i=0;i<n*m;i++){
		cin>>f[i];
	}
	u=f[0];
	int y=0;
	sort(f,f+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(f[i]==u){
			u=y+1;
			break;
		}
		y++;
	}
	int hang=ceil(float(u)/float(n));
	cout<<hang<<" ";
	if(hang%2==1){
		if(u%n==0){
			cout<<n;
		}else{
			cout<<u%n;
		}
	}else{
		cout<<n-(u%n)+1;
	}
}
