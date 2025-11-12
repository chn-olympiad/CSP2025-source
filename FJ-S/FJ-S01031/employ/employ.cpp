#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],s1[505],sum1,wz[505],sy[505],mg,fa;
int d=998244353;
string s;
int ef(int x){
	int l=1,r=505,mid=(l+r)/2,maxmin;
	while(l<r){
		if(c[mid]<=x){
			l=mid+1;
		}else{
			maxmin=min(maxmin,mid);
		}
	}
	return maxmin;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int sum=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			s1[i+1]=1;
			sum1++;
			wz[sum1]=i+1;
		}else{
			s1[i+1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=d;
	}
	if(sum1<m){
		cout<<"0";
		return 0;
	}
	if(sum1==n){
		cout<<sum;
		return 0;
	}
	if(wz[1]>c[n]){
		cout<<"0";
		return 0;
	}
	
	return 0;
}
