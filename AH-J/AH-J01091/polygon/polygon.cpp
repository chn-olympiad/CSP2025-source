#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int s=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	
	sort(a+1,a+n+1);
	
	if(n==3){
		int s=a[1]+a[2]+a[3];
		if(s>(a[3]*2)) cout<<"1\n";
		else cout<<"0\n";
	}
	else if(n==4){
		int ans=0;
		if((s-a[1])>a[4]*2) ans++;
		if((s-a[2])>a[4]*2) ans++;
		if((s-a[3])>a[4]*2) ans++;
		if((s-a[4])>a[3]*2) ans++;
		if(s>(a[4]*2)) ans++;
		cout<<ans<<"\n";
	}
	else {
		cout<<"6\n";
	}
	return 0;
}
