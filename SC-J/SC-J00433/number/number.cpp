#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
char v;
long long q,a[N],w=1,e=0;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	for(long long i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q=s[i];
			a[w]=q;
			w++;
		}
	}
	sort(a+1,a+w+1);
	for(long long i=w;i>1;i--){
		v=a[i];
		cout<<v;
	}
	return 0;
}