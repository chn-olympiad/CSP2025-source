#include<bits/stdc++.h>
using namespace std;
int a[1000005],l,t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t]=s[i]-48;
			t++; 
			}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--) cout<<a[i];	

return 0;
}
