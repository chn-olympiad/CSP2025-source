#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}
	for(int i=a.size()-1;i>=0;i--){
		for(int j=a.size()-1;j>=i;j--){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(long unsigned int i=0;i<=a.size()-1;i++){
		cout<<a[i];
	}
	    return 0;
}
