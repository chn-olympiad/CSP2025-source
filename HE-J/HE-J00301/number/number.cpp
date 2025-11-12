#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+50;
long long a[N],n;
char b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=1;
	long long m=1;
	while(cin>>b[n]) n++;
	long long flag0=0;
	for(long long i=1;i<=n;i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[m]=b[i]-'0';
			m++;
		}
		else flag0=1;
	}
	if(flag0=0){
		for(long long i=1;i<=n;i++){
			b[i]=b[i]-'0';
		}
		sort(b,b+m);
		if(b[1]==0){
			cout<<0;
			return 0;
		}
		for(long long i=1;i<=n;i++){
			cout<<b[i];
		}
	}
	sort(a,a+m);
	reverse(a,a+m);
	for(long long i=0;i<=m-2;i++){
		cout<<a[i];
	}
	return 0;
}
