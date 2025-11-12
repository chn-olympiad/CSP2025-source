#include<bits/stdc++.h>
using namespace std;
string s;
int sum,a[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    	    a[++sum]=s[i]-'0';
    	}
    }
    sort(a+1,a+sum+1);
    if(a[sum]==0){
    	cout<<0;
    	return 0;
    }
    for(int i=sum;i>=1;i--){
    	cout<<a[i];
    }
    return 0;
}