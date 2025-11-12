#include<bits/stdc++.h>
using namespace std;
const int N=501;
int n,m,c[N],ans;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	sort(s.begin(),s.end());
	do{
		int cnt1=0,cnt2=0;
		for(int j=0;j<n;j++){
			if(cnt2>=c[j])	continue;
			if(s[j]=='1'){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		if(cnt2>m)	ans++;
	}while(next_permutation(s.begin(),s.end()));
	cout<<ans;
	return 0;
}