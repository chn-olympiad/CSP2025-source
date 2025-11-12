#include<bits/stdc++.h>
using namespace std;
string s;
int a[105];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
	if(s[i]>='0'&&s[i]<='9'){
	    int k=s[i]-'0';
	    a[k]++;
	}
    }
    for(int i=9;i>=0;i--){
	for(int j=1;j<=a[i];j++){
	    cout<<i;
	}
    }
    return 0;
}
