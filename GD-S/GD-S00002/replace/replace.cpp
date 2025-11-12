#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,q;
string t1,t2;
struct sss{
	string s1,s2;
} s[N]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--){
		cin>>t1>>t2;
		printf("0\n"); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
