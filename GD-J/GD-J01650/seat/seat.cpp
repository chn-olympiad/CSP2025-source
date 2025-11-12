#include<bits/stdc++.h>
using namespace std;
int p[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c=a*b;
	for(int i=1;i<=c;i++){
		cin>>p[i];
	}
	int xm=p[1];
	sort(p+1,p+1+c);
	int ans=0;
	for(int i=1;i<=c;i++){
		if(p[i]==xm&&p[i]!=p[i+1]) {
			ans=c-i+1;
			break;
		}
	}
	cout<<(ans-1)/a+1<<" ";
	if(((ans-1)/a+1)%2==1){	
		if(ans%b==0) cout<<b;
		else cout<<ans%b;
	}
	else {
		if(ans%b==0) cout<<1;
		else cout<<b-ans%b+1;
	}
	return 0;
}
