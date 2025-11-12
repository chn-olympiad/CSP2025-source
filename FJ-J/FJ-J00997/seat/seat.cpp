#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[10005],val,now,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	val=s[1];
	sort(s+1,s+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(s[i]==val){
			now=i;
			break;
		}
	}
	c=(now-1)/n+1;
	if(c%2==1){
		r=now-(c-1)*n;
	}else{
		r=n-(now-(c-1)*n-1);
	}
	cout<<c<<' '<<r;
	return 0;
} 
