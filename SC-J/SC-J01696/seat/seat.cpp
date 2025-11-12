#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int r=a[1];
	int set=0;
	sort(a,a+m*n+1);
	for(int i=m*n;i>=1;i--){
		set+=1;
		if(a[i]==r){
			break;
		}
	}
	int nr,mr;
	if(set%n==0){
		nr=set/n;
	}else{
		nr=set/n+1;
	}
	
	if(nr%2==1){
		mr=set-(nr-1)*n;
	}else{
		mr=n-(set-(nr-1)*n)+1;
	}
	cout<<nr<<" "<<mr;
	
	
	return 0;
}