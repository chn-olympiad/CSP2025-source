#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a;
    long long b=0;
    int flag=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[b]=s[i];
            b++;
        }
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<i;j++){
        	if(a[j]<a[i]){
        		swap(a[j],a[i]);
        		flag=1;
			}
			if(flag!=1) break;
		}
    }
    for(int i=0;i<b;i++) cout<<a[i];
    return 0;
}
