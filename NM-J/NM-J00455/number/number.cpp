#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
	int n=s.size();
    long long x=0;
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            x++;
            a[x]=s[i]-'0';
        }
    }
    sort(a+1,a+1+x);
    for(int i=x;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
