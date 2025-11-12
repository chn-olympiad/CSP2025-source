#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n,m;
string s;
int c[501];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

    scanf("%d%d",&n,&m);
    cin>>s;
    bool ff = true;
    for(int i = 0;i<s.size();i++){
    	if(s[i] == '0'){
    		ff = false;
    		break;
		}
	}
    for(int i = 1;i<=n;i++){
    	scanf("%d",&c[i]);
	}
	if(ff){
		long long sum = 1;
		for(int i = 1;i<=n;i++){
			sum = ((sum%mod)*(i%mod))%mod;
		}
		printf("%lld",sum%mod);
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
