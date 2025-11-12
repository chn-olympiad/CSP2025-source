#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number3.in","r",stdin);
    freopen("number3.out","w",stdout);
    string s,s2;
    char b;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&'9'>=s[i]){
            s2=s2+s[i];
        }
    }
    for(int i=0;i<s2.size();i++){
        for(int j=i+1;j<s2.size();j++){
        	if(s2[j]>s2[i]){
        		b=s2[i];
        		s2[i]=s2[j];
        		s2[j]=b;
			}
    	}
    }
    cout<<s2;
    return 0;
}
