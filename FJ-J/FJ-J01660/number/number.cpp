#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    int o=1;
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
    	if(int(s[i])>=48&&int(s[i])<=58){
    		num[o]=int(s[i])-48;
    		o++;
    	}
    }
    o--;
    sort(num+1,num+o+1);
    for(int i=o;i>=1;i--)
    cout<<num[i];
	return 0;
}
