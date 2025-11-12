#include<bits/stdc++.h>
using namespace std;
string s1,s2="",ans;
long long len1,len2,sum[15],an=0;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s1;
len1=s1.size();
if(len1==1){cout<<s1;return 0;}  
 for(int i=0;i<len1;i++)
   {
   	if(s1[i]=='0') {sum[0]++;an++;}
    if(s1[i]=='1') {sum[1]++;an++;}
    if(s1[i]=='2') {sum[2]++;an++;}
    if(s1[i]=='3') {sum[3]++;an++;}
    if(s1[i]=='4') {sum[4]++;an++;}
    if(s1[i]=='5') {sum[5]++;an++;}
    if(s1[i]=='6') {sum[6]++;an++;}
    if(s1[i]=='7') {sum[7]++;an++;}
    if(s1[i]=='8') {sum[8]++;an++;}
    if(s1[i]=='9') {sum[9]++;an++;}
   }
   for(int i=1;i<=an;i++)
   {
   if(sum[9]>=1) {s2='9';ans=ans+s2;sum[9]--;}
   if(sum[8]>=1) {s2='8';ans=ans+s2;sum[8]--;}
   if(sum[7]>=1) {s2='7';ans=ans+s2;sum[7]--;}
   if(sum[6]>=1) {s2='6';ans=ans+s2;sum[6]--;}
   if(sum[5]>=1) {s2='5';ans=ans+s2;sum[5]--;}
   if(sum[4]>=1) {s2='4';ans=ans+s2;sum[4]--;}
   if(sum[3]>=1) {s2='3';ans=ans+s2;sum[3]--;}
   if(sum[2]>=1) {s2='2';ans=ans+s2;sum[2]--;}
   if(sum[1]>=1) {s2='1';ans=ans+s2;sum[1]--;}
   if(sum[0]>=1) {s2='0';ans=ans+s2;sum[0]--;}
}
 cout<<ans;
 fclose(stdin);
 fclose(stdout);
   return 0;
}
