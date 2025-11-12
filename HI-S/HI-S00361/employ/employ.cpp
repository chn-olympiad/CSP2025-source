#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,cnt=1,cnt2;
string s;
int c[505];
bool b[505];
void A(){
	int temp=n,sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			sum++;
			temp--;
		} 
		if(sum==(n-m)){
			break;
		}
	}
	for(int i=1;i<=temp;i++){
		cnt=cnt%mod*i;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) cnt2++;
	}
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0';
	}
	A();
	printf("%d",cnt%mod);
	return 0;
}
