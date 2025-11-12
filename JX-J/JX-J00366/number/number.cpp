#include<bits/stdc++.h>
using namespace std;
string a;
int s[1000050],p=0;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
            p++;
            s[p]=a[i]-'0';
        } 
    }
    sort(s+1,s+1+p);
    for(int i=p;i>=1;i--) cout<<s[i];
    cout<<endl;
	return 0;
}