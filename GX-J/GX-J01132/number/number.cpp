#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.in","w",stdout);
	int n;
    string s;
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            a[i]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    return 0;
}
