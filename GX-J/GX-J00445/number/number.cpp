#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    long long v[1000005]={0},m=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            v[m++]=s[i]-'0';
        }
    }
    sort(v,v+m+1);
    for(int i=m;i>=1;i--){
		cout<<v[i];
	}
    return 0;
}
