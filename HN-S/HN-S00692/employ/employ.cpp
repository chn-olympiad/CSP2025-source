#include<bits/stdc++.h>
using namespace std;
#define IO(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N = 1e3 + 7;
const int mod = 998244353; 
int n,n1,m;
string S;
vector<int> a;
int s[N];
int c[N];
bool t,t2=1;
long long d=1;
int main(){
	IO("employ");
	scanf("%d%d",&n,&m);
	n1=n;
	cin>>S;
	for(int i=0;i<S.size();i++){
		s[i+1]=s[i]+1;
		if(S[i]=='0') a.push_back(i+1),s[i+1]--,t;
		if(S[i]=='1') t2=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(!c[i]) n1--;
	}
	if(n1<m ||a.size()>n-m){
		printf("0");
		return 0;
	}
	if(t){
		for(int i=n1-m;i<m;i++) (d*=i)%=mod;
		printf("%d",d);
		return 0;
	}
	if(m==1){
		if(!t2){
			for(int i=1;i<=n;i++) (d*=i)%=mod;
			return 0; 
		}
	}
	return 0;
}  
