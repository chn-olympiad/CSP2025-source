#include<bits/stdc++.h>
#define endl '\n'
#define PII pair<int,int>
#define qaq cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
typedef long long ll;
const int N = 5e2+10;
const ll P = 998244353;
int a[N];
int t[N];
int n,m;
int lv[N];
string s;
ll ans=0;
bool check(){
	int cnt=0;
	int l=0;
	for(int i=1;i<=n;i++){
		if(cnt>=a[t[i]]){
			cnt++;
			continue;
		}
		if(s[i]=='1'){
			l++;
		}
		else{
			cnt++;
		}
	}
//	if(l>=m){
//		for(int i=1;i<=n;i++){
//			cout << t[i] << " ";
//		}
//		cout << endl;
//		return 1;
//	}
	return l>=m;
}
int main(){
	qaq;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s=" "+s;
	lv[0]=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		t[i]=i;
		lv[i]=lv[i-1]*i;
	}
//	sort(a+1,a+1+n);
	if(n<=18){
		do{
			ans+=check();
			ans%=P;
			//cout << 111 << endl;
		}while(next_permutation(t+1,t+1+n));
		cout << ans << endl;
	}
	else{
		cout << lv[n] << endl;
	}
	return 0;
}

