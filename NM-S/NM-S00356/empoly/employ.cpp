#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string str;
	long long m(0),n(0);
	scanf("%lld%lld",&m,&n);
	cin>>str;
	vector<int> te(n+1);
	for(long long i=0;i<str.size();i++){
		te[i]=str[i]-'0';
		
	}
	vector<int> pe(n+1);
	for(long long i=0;i<n;i++){
		long long ls=0;
		scanf("%lld",&ls);
		pe[i]=ls;
	}
	vector<int> x(n+1);
	long long co=0;
	long long peo=0;
//	for(long long i=0;i<m;i++){
//		if(co>pe[i]){
//			co++;
//			continue;
//		}
//		if(te[i]==1){
//			co++;
//		}else{
//			peo++;
//		}
//		cout<<peo<<" ";
//	}
	

	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			
			if(x[i]==x[j]){
				peo++;

				
			}
	}
	}
	peo/=2;
	peo=peo%998244353;
	printf("%lld",peo);
	return 0;
}
