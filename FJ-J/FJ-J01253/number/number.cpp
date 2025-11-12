#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string st; cin>>st;
	int len=st.size();
	for(int i=0;i<len;i++){
		if(st[i]<='9'&&st[i]>='0'){
			a[++cnt]=st[i]-'0';
		}	
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--)
		cout<<a[i];
	cout<<endl;
	return 0;
}