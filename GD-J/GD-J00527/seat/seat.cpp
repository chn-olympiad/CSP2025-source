#include<iostream>
#include<cstdio>
using namespace std;
int n,m,r,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		int tmp;
		cin>>tmp;
		if(tmp>r) cnt++;
	}
	int l=cnt/n;
	if(l*n!=cnt) l++;
	cnt=cnt-n*(l-1);
	if(l%2){
		cout<<l<<" "<<cnt;
	}else{
		cout<<l<<" "<<n-cnt+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
