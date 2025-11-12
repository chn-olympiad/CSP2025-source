#include <bits/stdc++.h>
using namespace std;
bool mysort(string x,string y){
    if(x>=y){
        return true;
    }
    else return false;
}
int j=0;
string e[100000];
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   string s;
   cin>>s;
   for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            e[j]=s[i];
            j++;
        }

   }
   sort(e,e+j,mysort);
   for(int i=0;i<j;i++){
   	 cout<<e[i];
   }
    return 0;
}
