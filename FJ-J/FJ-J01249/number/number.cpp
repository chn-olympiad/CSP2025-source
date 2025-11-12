#include<bits/stdc++.h>
using namespace std;
int s,x=0,n;
int a[1010];
int main(){
	freopen("number.in","r",stdin);
	freopen("numbre.out","w",stdout);
	cin>>s;
	while(s!=0){
		x++;
		a[x]=s%10;
		s/=10;
		a[x]=-a[x];
	}
	sort(a+1,a+x+1);
	for(int j=1;j<=x;j++){
		a[x]=-a[x];
	}
	for(int j=x;j<=1;j++){
		n+=a[x]*j;
		x--;
	}
	cout<<n;
	return 0;
}
