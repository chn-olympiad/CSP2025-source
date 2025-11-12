#include<bits/stdc++.h>
using namespace std;
int n,m,a,a1,t=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>a1){
			t++;
		}
	}
	int l=(t-1)/n+1;
	if(l%2==1){
		cout<<l<<" "<<(t-1)%n+1;
	}else{
		cout<<l<<" "<<n-(t-1)%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
