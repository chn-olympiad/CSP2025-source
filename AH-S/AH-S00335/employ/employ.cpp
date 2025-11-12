#include<bits/stdc++.h>
using namespace std;
long long n,m,c[100005];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    getline(cin,s);
    getline(cin,s);
    long long sum_a=0;
    for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0){
		    sum_a++;
		}
	}
	cout<<"\n";
	bool oa=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			oa=0;
	    }
    }
    if(oa==1){
		long long ans=1,ans2=1;
		for(int i=1;i<=sum_a;i++){
			ans*=i;
			ans%=998244353;
		}
		for(int i=1;i<=100-sum_a;i++){
			ans2*=i;
			ans2%=998244353;
		}
		cout<<(ans*ans2)%998244353;
		return 0;
    }
}
