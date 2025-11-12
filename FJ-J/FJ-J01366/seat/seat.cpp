#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a,k,s1,s2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d",&a);
	k=1;
	for(int i=2;i<=n*m;i++){
		int x;
		scanf("%d",&x);
		if(x>a)
			k++;}
	s1=(k-1)/n+1;
	s2=(k-1)%n+1;
	if(s1%2==0)
		s2=n+1-s2;
	cout<<s1<<" "<<s2<<endl;
	return 0;
} 
