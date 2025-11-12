#include <bits/stdc++.h>
using namespace std;
long long n,c,a[100010],s,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==0){
		cout<<1;
		return 0;
	}else if(c==1){
		cout<<1;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+2;j<=n;j++){
			for(long long k=i;k<=j;k++){
				s=s^a[k];
			}
			if(s==c)ans++;
		}
	}
	cout<<ans;
	return 0;
} 

