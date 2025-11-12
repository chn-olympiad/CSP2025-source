#include<bits/stdc++.h>
using namespace std;
string a;int c[520],ct0,ct1,cmx=-1;
long long jiec(int jieshu){
	long long ans=1;
	for(int i=2;i<=jieshu;i++){
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];	
	}
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]=='0')ct0++;
		else ct1++;
	}
	if(!ct0){
		cout<<jiec(n);
		return 0;
	}
	if(m==1){
		if(c[n]>=n){
			cout<<jiec(n)-1;
		}else cout<<jiec(n-1);
	}
	return 0;
}
