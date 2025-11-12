#include <bits/stdc++.h>
using namespace std;
string s;
int a[10000],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(isdigit(c)){
            n++;
            a[n]=c^48;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++)
            if(a[i]<a[j]) swap(a[i],a[j]);
    }
    for(int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
	return 0;
}
