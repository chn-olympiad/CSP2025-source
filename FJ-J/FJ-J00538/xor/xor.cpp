#include <bits/stdc++.h>
using namespace std;
int n,a[5100],ans;
int twofind(int x){
	int maxx=INT_MAX,c=0;
	for(int i=1;i<=n;i++){
		int s=abs(x-a[i]);
		if(s<maxx){
			maxx=s;
			c=i;
		}
	}
	return c;
}
int much(int x){
	int s=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x;j++){
			if(a[i]+a[j]==a[x]){
				s++;
			}
		}
	}
	if(s==0){
		return 1;
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<ans;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		//	cout<<ans;
			int x=a[i]+a[j];
			int y=abs(a[i]-a[j]);
			for(int k=twofind(y);k<=twofind(x);k++){
				ans++;
				ans+=much(i)*much(j)*much(k);
			}
		}
	}
	cout<<ans;
	return 0;
} 
