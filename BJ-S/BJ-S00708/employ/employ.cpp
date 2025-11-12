#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans,c[15],p[15],v[15];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	do{
		int ret=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				v[i]=0;
			}
			else{
				int res=0;
				for(int j=1;j<i;j++){
					res+=(!v[j]);
				}
				if(res>=c[p[i]]){
					v[i]=0;
				}
				else{
					v[i]=1;
					ret++;
				}
			}
		}
		if(ret>=m){
			ans++;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
