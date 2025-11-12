#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m+1];
	for(int i=0;i<n*m;i++) cin>>s[i];
	int u=s[0];
	int count=1;
	for(int i=1;i<n*m;i++){
		if(u<s[i]) count++;
	}
	int li;
	if(count%n!=0)  li = (count/n)+1;
	else li = (count/n);
	int hang;
	if(li%2==1) hang = count-(li-1)*n;
	else hang = n-(count-(li-1)*n)+1;
	cout<<li<<' '<<hang;
	return 0;
} 
