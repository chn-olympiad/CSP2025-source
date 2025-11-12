#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,c[501];
string s;
bool f1=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=0;i<int(s.length());++i){
		if(s[i]=='0'){
			f1=0;
		}
	}
	if(n==m){
		if(f1){
			sort(c+1,c+n);
			bool opp=1;
			for(int i=1;i<=n;++i){
				if(c[i]<i){
					opp=0;
					break;
				}
			}
			if(opp==0) cout<<0;
			else cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else cout<<0;
	return 0;
}
