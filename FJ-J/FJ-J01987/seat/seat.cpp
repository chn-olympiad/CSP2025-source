#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,a,level=1;
	cin>>n>>m>>r;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>r) level++;
	}
	int yushu,hang=level/n+(level%n!=0);
	cout<<hang<<" ";
	if(level%n==0){
		if(hang%2==1) cout<<n;
		else cout<<1;
	}
	else{
		yushu=level-(hang-1)*n;
		if(hang%2==1) cout<<yushu;
		else cout<<n-yushu+1;
	}
	return 0;
}