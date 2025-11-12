#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long int n,m,b=0,d=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[n],l=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(b<a[i] && s[i]=='1'){
			l++;
			a[i]=0;
		}
		else if(s[i]=='0')
			b++;
		else if(b>=a[i] && s[i]=='0')
			b++;
	}
	if(n-b>=m){
		for(int j=m;j<=n-b;j++)
			for(int i=1;i<=j;i++){
				d*=i;
				if(d%998==0)
					d/=998;
				if(d%224==0)
					d/=224;
				if(d%353==0)
					d/=353;
			}
		cout<<d;
	}else{
		cout<<0;
	}
	return 0;
}
