#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+4;
int a[N];
bool cmp(int n,int m){
	return n>m;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int ansdf=1;
	for(int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[ansdf]=s[i]-'0';
			ansdf++;
		}
	}
	sort(a+1,a+ansdf+1,cmp);
	for(int i=1;i<ansdf;i++){
		printf("%lld",a[i]);
	}
	return 0;
} 
