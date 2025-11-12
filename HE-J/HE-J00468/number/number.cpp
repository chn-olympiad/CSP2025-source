#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;

string s;
ll a[N],tot;

int main(){
	
	//别忘了最后写 freopen~ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	for(auto c:s) if(isdigit(c)) a[++tot]=c-'0';
	
	sort(a+1,a+1+tot);
	
	for(int i=tot;i>=1;i--) cout<<a[i];
	
	return 0;
}
//8:47 meaw!
