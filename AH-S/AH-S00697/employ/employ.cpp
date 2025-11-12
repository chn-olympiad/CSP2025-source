#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int maxn=550;
typedef long long ll;
const ll P=998244353;
int m,n;
ll ans;
string s;
int c[maxn],a[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];a[i]=i;
	}
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
			if(s[i]=='0'){
				cnt++;
			}
			else{
				sum++;
			}
		}
		if(sum>=m){
			ans++;
		}
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
