#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cut=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=58){
            a[cut]=s[i]-48;
            cut++;
        }
    }sort(a,a+cut);
    for(int i=cut-1;i>=0;i--){
        cout<<a[i];
    }
	return 0;
}
