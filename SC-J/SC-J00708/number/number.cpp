#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000000+10;
string s;
int l,k,p;
int b[maxn];
long long a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if('9'-48>=s[i]-48){
			if('0'-48<=s[i]-48){
			k++;
			a[k]=s[i]-48;
			}
		}
	}
	sort(a,a+k);
	while(a[0]==0){
	p++;
	b[p]=0;
	a[0]=-1;
	}
	for(int i=k-p;i>0;i--){
		cout<<a[i];
	}
	for(int i=1;i<=p;i++){
		cout<<b[i];
	}
	return 0;
}//99998888887777766666655555544444433332111000000000
///99998888887777766666655555544444433332111000000000