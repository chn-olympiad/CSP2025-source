#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a[20]={0};
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    } 
    for(int i=9;i>=0;i--){
    	for(int j=1;j<=a[i];j++){
    		printf("%lld",i);
		}
	}
    return 0;
}
