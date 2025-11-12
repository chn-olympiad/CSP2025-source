#include<bits/stdc++.h>
using namespace std;
const int nx=1e6+5;
string s;
int a[nx]={0};
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.length()==1&&(s[0]<='9'&&s[0]>='0')){
    	cout<<int(s[0]-'0');
    	return 0;
	}int n=s.length();
	for(int i=0; i<n; i++){
		if(s[i]<='9'&&s[i]>='0') a[i]=s[i]-'0'+1;
	}sort(a,a+n);
    for(int i=n; i>0; i--){
    	if(a[i]==0) continue;
    	cout<<a[i]-1;
	}
    return 0;
}