#include <bits/stdc++.h>
using namespace std;
int s[105];
int ans1,ans2;
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int tar=s[1],num;
	sort(s,s+n*m+1);
	for(int i=1;i<=n*m;i++)if(s[i]==tar){num=n*m-i+1;break;}
	if(num%n!=0){
		if((num/n)%2==0){ans1=num/n+1;ans2=num%n;}
		else {ans1=num/n+1;ans2=n-num%n+1;}
	}else{
		if(num/n%2==0){ans1=num/n;ans2=1;}
		else {ans1=num/n;ans2=n;}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
