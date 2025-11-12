#include<bits/stdc++.h>
using namespace std;
const int N=505,M=998244353;
int n,m,c[N],p[N],ans,cnt;
long long res;
string s;
void init(){
	ans=0;
	cnt=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'&&cnt<c[p[i]])ans++;
		else cnt++;
		if(ans==m){
			res=(res+1ll)%M;
			break; 
		}
	}
	while(next_permutation(p+1,p+1+n)){
		init();
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&cnt<c[p[i]])ans++;
			else cnt++;
			if(ans==m){
				res=(res+1ll)%M;
				break; 
			}
		}
	}
	cout<<res;
	return 0;
} 
