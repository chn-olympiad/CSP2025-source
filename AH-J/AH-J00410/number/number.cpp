#include<bits/stdc++.h>
using namespace std;
int b[1000000],s=0;
bool y=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
     if(a[i]>='0'&&a[i]<='9') {
		 if(a[i]!='0'){
			 y=0;
		 }
        s++;
        b[s]=a[i]-'0';
     }
    }
   if(y){
	   cout<<0;
	   return 0;
   }
    sort(b+1,b+s+1);
    for(int i=s;i>=1;i--){
     cout<<b[i];
    }
    return 0;
}
