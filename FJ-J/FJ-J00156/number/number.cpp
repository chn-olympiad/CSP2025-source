#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

string s;
int n,a[maxn];
int cnt=0;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i){
		if('0'<=s[i] && s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	
	sort(a,a+cnt,cmp);
	
	for(int i=0;i<cnt;++i){
		cout<<a[i]; 
	}
	cout<<'\n';
	
	return 0;
}
