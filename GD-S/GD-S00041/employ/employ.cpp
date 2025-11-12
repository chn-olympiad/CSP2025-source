#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,a[N],p[N],res;
string s;
inline int adm(int x,int y){
	return (x+y>=mod?x+y-mod:x+y);
}
bool check(){
	int tfil=0,res;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0' or tfil>=a[p[i]])tfil++;
		if(tfil+m>n){
			sort(p+i+1,p+n+1,[&](int x,int y){return x>y;});
			return false;
		}
	}
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)p[i]=i,cin>>a[i];
	if(m==n){
		for(auto& i:s){
			if(i=='0'){
				cout<<0<<'\n';
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(!a[i]){
				cout<<0<<'\n';
				return 0;
			}
		}
		res=1;
		for(int i=1;i<=n;i++)res=1ll*res*i%mod;
		cout<<res<<'\n';
		return 0;
	}
	do{
		res=adm(res,check());
	}while(next_permutation(p+1,p+n+1));
	cout<<res<<'\n';
}