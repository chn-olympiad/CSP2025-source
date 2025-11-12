#include<bits/stdc++.h>
using namespace std;
string str;
int cnt[19];
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    cin>>str;
    long long t=str.size();
    for(long long i=0;i<t;i++){
		if(str[i]-'0'>=0&&str[i]-'0'<=9){
			cnt[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<cnt[i];j++){
			cout<<i;
		}
	}
    return 0;
}
