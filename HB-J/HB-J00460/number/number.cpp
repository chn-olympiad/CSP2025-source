#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long ans=0;
    cin>>s;
    long long k=s.size()+10;
    long long a[k];
    for(long long i=0;i<s.size();i++){
        if(s[i]>=97&&s[i]<=123) continue;
        else{
            ans++;
            a[ans]=s[i]-'0';
        }
    }
    sort(a+1,a+1+ans);
    for(long long i=ans;i>0;i--){
        cout<<a[i];
    }
	return 0;
}
