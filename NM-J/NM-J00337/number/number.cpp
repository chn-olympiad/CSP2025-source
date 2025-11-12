#include<bits/stdc++.h>
using namespace std;
string s;
char c[100005];
int a[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            c[i]=s[i];
            a[i]=c[i]-'0';
            if(a[i]<a[i+1]){
    		swap(a[i],a[i+1]);
		}
		cout<<a[i];
        }
    }
    return 0;
}

