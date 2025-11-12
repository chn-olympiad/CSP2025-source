#include<bits/stdc++.h>
using namespace std;
string a;
map<int,int> mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int len=a.size();
    for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			mp[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++){
			cout<<i;
		}
	}
    return 0;
}
