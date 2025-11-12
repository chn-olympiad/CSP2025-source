//T1
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+101;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int q=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[q]=(int)s[i]-48;q++;
		}
	}
	sort(a+1,a+q+1);
	for(int i=q;i>=2;i--){
		cout<<a[i];
	}
	return 0;
}
