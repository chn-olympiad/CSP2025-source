#include <bits/stdc++.h>
using namespace std;
string s1;
int a[11];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    int l1=s1.size();
    for(int i=0;i<l1;i++){
        a[s1[i]-'0']++;    
     }
     for(int i=9;i>=0;i--){
		 for(int j=1;j<=a[i];j++){
			 cout<<i;
		 }
     }
    return 0;
}
