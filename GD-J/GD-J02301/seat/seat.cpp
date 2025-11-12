#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=0,c,r,a;
	int s[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	b=s[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=i+1;j++){
			if(s[j]<s[j+1]) swap(s[j],s[j+1]);
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b==s[i]) a=i;
	}
	if(a%n!=0) c=a/n+1;
	else c=a/n;
	if(c%2==0) r=n-a%n+1;
	else if(a%n==0) r=n;
	else r=a%n;
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I AK this problem
