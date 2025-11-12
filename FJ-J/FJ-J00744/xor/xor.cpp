#include<bits/stdc++.h>
using namespace std;
long long n,k,a,t,ans;
bool flag;
vector<long long> num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	while(n--){
		scanf("%lld",&a);
		if(a==k){
			ans++;
			num.clear();
			continue;
		}
		t=a;
		t^=k;
		flag=true;
		for(int i=num.size()-1;i>=0;i--)
		if(t==num[i]){
			ans++;
			num.clear();
			flag=false;
			break;
		}
		else
		t^=num[i];
		if(flag)
		num.push_back(a);
	}
	printf("%lld",ans);
	return 0;
}
