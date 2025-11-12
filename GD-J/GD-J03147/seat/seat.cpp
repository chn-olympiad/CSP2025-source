#include<bits/stdc++.h>
using namespace std;
int x,y;
int a[105];
int main(){
	freopen("seet.in","r",stdin);
	freopen("seet.out","w",stdout);
	cin>>x>>y;
	int n=x*y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=a[1];
	int s;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i++){
		if(a[i]==t){
			s=i;
		}
	}
	s=n-s;
	t=y/2;
	s=s%y;
	if(s>x){
		t+=1;
		s-=x;
		s=x-s;
	}
	cout<<t<<s;
	return 0;
}
