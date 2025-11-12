#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M=1e6+5;
string s="";
ll a[M],temp=1,num=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num=(int) s[i];
			a[temp]=num-48;
			temp++;
		} 
	}
	sort(a+1,a+temp);
	for(int i=temp-1;i>=1;i--) cout<<a[i];
	return 0;
}
