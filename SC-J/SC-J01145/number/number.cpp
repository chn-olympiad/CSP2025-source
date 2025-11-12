#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010];
long long jsq=0;
long long k,maxn;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[jsq]=s[i]-'0';
			jsq++;
		}
	}
	for(long long j=0;j<jsq;j++){
		maxn=a[0];
		k=0;
		for(long long i=1;i<jsq;i++){
			if(a[i]==-1) continue;
			if(a[i]>maxn){
				maxn=a[i];
				k=i;
			}
		}
		printf("%lld",maxn);
		a[k]=-1;
	}
	return 0;
}