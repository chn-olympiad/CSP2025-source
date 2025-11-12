#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,c[N],p[N],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='$'+s;
	for(int i=1;i<=n;i++) cin>>c[i],p[i]=i;
	do{
		int cnt=0,t=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]) cnt++;
			else if(s[i]=='0') cnt++;
			else t++;
			if(t>=m) {
				ans++;
				break;
			}
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

