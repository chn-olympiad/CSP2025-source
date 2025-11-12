#include<bits/stdc++.h>
using namespace std;
int main(){
 freopen("number.in","r",stdin);
 freopen("number.out","w",stdout);
 int r,c=0,a[1000006]={};
 string s;
 cin>>s;
 for(int i=0;i<s.size();i++){
    if(s[i]>='0'&&s[i]<='10'){
        c++;
        a[i]=s[i];
    }
 }
 sort(a,a+c);
 for(int j=0;j<c;j++){
    cout<<a[j];
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
