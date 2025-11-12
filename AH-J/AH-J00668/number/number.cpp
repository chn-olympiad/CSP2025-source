#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=300;
string str;
LL t[N];
bool ok=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	LL len=str.size();
	for(LL i=0;i<len;i++){
		t[LL(str[i])]++;
		//cout<<str[i]<<' '<<t[LL(str[i])]<<endl;
	}
	for(LL i='9';i>='0';i--){
		if(ok==1&&i=='0'){
			puts("0");return 0;
		}
		for(LL j=1;j<=t[i];j++)	printf("%lld",i-'0'),ok=0;
	}
	return 0;
}
