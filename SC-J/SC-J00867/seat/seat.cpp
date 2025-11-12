#include<bits/stdc++.h>
using namespace std;
int n,m,a,s=1,s2,s3;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for (int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if (x>a){
			s++;
		}
	}
	s2=s%n;
	if (s2!=0){
		s3++;
	}
	else{
		s2=n;
	}
	s3+=s/n;
	cout<<s3<<' ';
	if (s3%2==1){
		cout<<s2;
	}
	if (s3%2==0){
		cout<<n-s2+1;
	}
	return 0;
} 