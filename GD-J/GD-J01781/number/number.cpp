#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string s;
long long len;
long long n;
long long a[maxn]={-1};
bool cmp(long long c,long long d) {
	return c>d;
}
void chushi(){
	for(int i=0;i<=maxn;i++){
		a[i]=-1;
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	sort(s.begin(),s.end());
	chushi();
	for(int i=0; i<len; i++) {
		if(s[i]-'0'>=10) {
			n=i-1;
			break;

		} else {
			a[i]=s[i]-'0';
		}
	}
	for(int i=0;i<=1000005;i++){
		if(a[i]==-1){
			n=i-1;
			break;
		}
	}
	sort(a,a+n+1,cmp);
	for(int i=0; i<=n; i++) {
		printf("%d", a[i]);
	}
	return 0;
}
