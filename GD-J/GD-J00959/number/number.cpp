#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define x first
#define y second
#define vt vector
#define pb push_back
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
const int INF=0x3f3f3f3f;
string s;
ll a[N],xx;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++xx]=s[i]-'0';
		}
	}
	sort(a+1,a+xx+1);
	for(int i=xx;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

