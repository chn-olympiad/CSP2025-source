#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],cnt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);

   cin>>s;
   /*cout<<"-------------:"<<endl;
   cout<<"0: "<<int('0');
   cout<<" 1: "<<int('1');
   cout<<" 2: "<<int('2');
   cout<<" 3: "<<int('3');
   cout<<" 4: "<<int('4');
   cout<<" 5: "<<int('5');
   cout<<" 6: "<<int('6');
   cout<<" 7: "<<int('7');
   cout<<" 8: "<<int('8');
   cout<<" 9: "<<int('9');
   cout<<"-------------:"<<endl;*/

   for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
                /*cout<<s[i]<<" "<<"on"<<"--";*/
           a[cnt]=int(s[i]-'0');
           cnt++;
        }

   }
   sort(a,a+cnt,cmp);
   for(int i=0;i<cnt;i++) cout<<a[i];
   fclose(stdin);
   fclose(stdout);
}
