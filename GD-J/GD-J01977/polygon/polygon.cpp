#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
using namespace std;
long long mo=998244353,n,a[5010],l,zhuda,Max,ans,k;
long long he(long long x,long long t,long long m){
	for(int i=x;i<=n;i++){
		t+=a[i];
		m++;
		t=t%mo;
		Max=max(Max,a[i]);
		if(t>=Max && m>=3){
			ans++;
		}
		he(i,t,m);
		t=0;
		m=0;
		Max=0;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k+=a[i]%mo;
		Max=max(Max,a[i]);
		
	}
	if(k>Max){
		ans++;
	}
//	zhuda=a[1];
//	for(int i=1;i<=n;i++){
//		he(i,0,0);
//	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
