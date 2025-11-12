#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,num=0,s[105];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		if(s[1]<s[i]){
			num++;
		}
	}
	c=(num/n)+1;
	r=num%c;
	cout<<c<<" "<<r;
	return 0;
} 
