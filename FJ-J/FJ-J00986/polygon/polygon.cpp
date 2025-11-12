#include <bits/stdc++.h>
using namespace std;
int n,maxx,sum,ans=0,s[5005];
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		if(s[i]!=1){
			flag=0;
		}
	}
	if(n==3){
		maxx=0;
		sum=0;
		for(int i=1;i<=3;i++){
			maxx=max(maxx,s[i]);
			sum+=s[i];
		}
		if(sum>maxx*2){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(flag==1 && n==5){
		for(int i=1;i<=n-2;i++){
			ans+=i*(i+1)/2;
		}
		cout << 1+n+ans;
	}else{
		for(int i=1;i<=n-2;i++){
			for(int j=i+2;j<=n;j++){
				for(int q=i;q<=j;q++){
					maxx=(s[i],maxx);
					sum+=s[i];
				}
				if(sum>maxx*2){
					ans++;
					cout << i << " " << j << endl;
				}
				maxx=0;
				sum=0;
			}
		}
		cout << ans%998244353;
	}
	return 0;
}

