#include <iostream>
#include <algorithm>
using namespace std;
int n,m,c[15],s[15],ans;
bool v[15];
inline bool chk(){
	int sum=0,ct=0;
	for(int i=1;i<=n;i++){
		if(ct>=m)return true;
		if(sum>=c[s[i]]||!v[i]){
			sum++;
			continue;
		}
		ct++;
	}
	return ct>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		v[i]=(ch=='1');
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)s[i]=i;
	do{
		if(chk())ans++;
	}while(next_permutation(s+1,s+1+n));
	cout<<ans;
}
