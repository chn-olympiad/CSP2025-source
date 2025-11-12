#include<bits/stdc++.h>
using namespace std;

long long a[5005],n,c=0;

void f(int t,string x){
	if(t==0){
		long long cnt=0,ma=0,d=0;
		for(int i=0;i<n;i++){
			if(x[i]=='1'){
				cnt+=a[i];d++;
				ma=max(ma,a[i]);
			}
		}
		if(ma*2<cnt&&d>2)c=(c+1)%998244353;
		return ;
	}
	f(t-1,x+"1");
	f(t-1,x+"0");
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	for(int i=0;i<n;i++)cin>>a[i];
	f(n,"1");f(n,"0");
	cout<<c/2;
	return 0;
} 
