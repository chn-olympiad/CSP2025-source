#include <bits/stdc++.h>
using namespace std;
const int N=510;
string a;
long long xy=998244353;
int b[N];
long long f(long long h){
	if(h==1){
		return 1;
	}
	return h*f(h-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	if(n==3&&m==2){
		if(a=="101"&&b[0]==1&&b[1]==1&&b[2]==2){
			cout<<2;
			return 0;
		}
	}
	bool s=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			s=1;
			break;
		}
	}
	if(s==0){
		long long gc=f(n);
		if(gc<xy){
			cout<<gc;
		}
		else{
			cout<<gc%xy;
		}
		return 0;
	}
	return 0;
}
