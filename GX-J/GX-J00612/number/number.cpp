#include<bits/stdc++.h>
using namespace std;
string s;
int k=1;
long long a[1000000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
	if(s[i]<='9'&&s[i]>='0'){
        a[k]=int(s[i]-'0');
        k++;
	}
}
for(int i=1;i<=k;i++){
    for(int j=i+1;j<=k;j++){
        if(a[j]<a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
}
for(int i=1;i<=k;i++){
    cout<<a[i];
}
return 0;
}
