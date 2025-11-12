#include <bits/stdc++.h>
using namespace std;

int n,m,c,r;
struct tester{
	int num,mark;
}s[1100];

bool cmp(tester x,tester y){
	return x.mark>y.mark;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].mark;
		s[i].num=i;
	}
	
	sort(s+1,s+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++){
		if(s[i].num==1){
			c=(i-1)/n+1;
			int k=i%n; if(k==0) k=n;
			if(c%2==1) r=k;
			else r=n-k+1;
			
			break;
		}
	}
	
	cout<<c<<' '<<r;
	return 0;
}
