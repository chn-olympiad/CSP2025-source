#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,s=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		s=a[0];
	}
	sort(a+0,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==s){
			s=i;
		}
	}
	if(s==n){
		cout<<1<<" "<<n;
	}
	else if(n==(s/n)+1){
		cout<<(s/n)+1<<" "<<(s%n)-1;
	}
	else{
		cout<<(s%n)+1<<" "<<(s/n)+2;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
