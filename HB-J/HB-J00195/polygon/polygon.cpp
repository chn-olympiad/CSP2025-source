#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int s=0,s1=a[j+i-1];
			for(int k=0;k<i;k++){
				s+=a[j+k];
			}
			//~ cout<<"i="<<i<<endl;
			//~ cout<<"s="<<s<<endl;
			//~ cout<<"s1="<<s1<<endl;
			if(s>s1*2){
				ans++;
				//~ cout<<"i="<<i<<endl;
				//~ cout<<"s="<<s<<endl;
				//~ cout<<"s1="<<s1<<endl;
			}
		}
	}
	cout<<ans%998244353<<endl;
	return 0;
}
