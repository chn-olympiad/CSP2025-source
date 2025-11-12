#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k;
long long a[N];
long long fun(long long x,long long y){
	long long x1=0;
	string x2="",y2="";
	while(x!=0){
		x1=x%2;
		x2=to_string(x1)+x2;
		x/=2;
	}
	long long y1=0;
	while(y!=0){
		y1=y%2;
		y2=to_string(y1)+y2;
		y/=2;
	}
	if(x2.size()<y2.size()){
		while(x2.size()<y2.size()) x2='0'+x2;
	}
	else if(x2.size()>y2.size()) while(y2.size()<x2.size()) y2='0'+y2;
	string s3="";
	long long i;
	for(i=0;i<x2.size();i++){
		if(x2[i]!=y2[i]) s3=s3+'1';
		else s3=s3+'0';
	}
	long long s=0,l=1; 
	for(i=s3.size()-1;i>=0;i--){
		s+=(s3[i]-'0')*l;
		l*=2;
	}
	return s;
}
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		if(i==1){
			long long s=fun(a[1],a[2]);
			for(long long j=3;j<=n;j++){
				s=fun(s,a[j]);
			}
			if(s==k) ans=max(ans,(long long)1);
		}
		if(i==2){
			for(long long j=1;j<=n;j++){
				for(long long k=i+1;k<=n;k++){
					long long s,s2;
					if(j!=1){
						s=fun(a[1],a[2]);
						for(long long h=3;h<=j;h++){
							s=fun(s,a[h]);
						}
					}
					else s=fun(a[1],a[1]);
					if(k+1<=n){
						s2=fun(a[k],a[k+1]);
					    for(long long h=k+2;h<=n;h++){
							s2=fun(s2,a[h]);
					    }
					}
					else  s2=fun(a[k],a[k]);
					if(s2==s&&s==k){
						ans=max(ans,(long long)2);
					}
				}
			}
		}
	}
	if(k==0){
		ans=0;
		for(i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
	}
	cout<<ans;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
