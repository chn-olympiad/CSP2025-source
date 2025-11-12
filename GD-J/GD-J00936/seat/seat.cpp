#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int b[n*m];
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int x=b[0];
	sort(b,b+n*m);
	int s;
	for(int i=n*m-1;i>=0;i--){
		if(b[i]==x){
			s=n*m-i-1;
			break;
		}
	}
	int s1,s2;
	s1=s/m;
	if(s1%2==0)s2=s%m+1;
	else s2=m-s%m-1;
	cout<<s1+1<<' '<<s2;
}
