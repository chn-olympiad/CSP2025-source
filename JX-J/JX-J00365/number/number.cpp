#include <bits/stdc++.h>
using namespace std;
string s;
int i,l,a[100000],j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number,out","w",stdout);
	cin>>s;
	l=s.size();
	for(i=0,j=0;i<l;i++){
	    if(s[i]>='0' && s[i]<='9'){
		    a[j]=s[i]-'0';
		    j++;
		}
	}
	sort(a,a+j);
	for(i=j-1;i>=0;i--){
	    cout<<a[i];
	}
	return 0;
}
