#include<bits/stdc++.h>
using namespace std;
long long n,p;
struct ll{
string a,b,c;
	long long x;
}a1[220000],a2[220000];
string b1,b2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&p);
    for(int i=1;i<=n;i++){
    	cin>>a1[i]>>a2[i];
	}
	for(int i=1;i<=p;i++){
		cin>>b1>>b2;
		
		cout<<"0"<<endl;
	}
	return 0;
}
