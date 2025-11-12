#include<bits/stdc++.h>
using namespace std;
long long numbers[1000001],ans=0;
string sum={};
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   string s;
   cin>>s;
   //cout<<s<<endl;
   for(int i=0;i<s.size();i++){
	   //cout<<i<<endl;
	   if(s[i]=='0'){
		   numbers[ans]=0;
		   ans++;
	   }
	   if(s[i]=='1'){
		   numbers[ans]=1;
		   ans++;
	   }
	   if(s[i]=='2'){
		   numbers[ans]=2;
		   ans++;
	   }
	   if(s[i]=='3'){
		   numbers[ans]=3;
		   ans++;
	   }
	   if(s[i]=='4'){
		   numbers[ans]=4;
		   ans++;
	   }
	   if(s[i]=='5'){
		   numbers[ans]=5;
		   ans++;
	   }
	   if(s[i]=='6'){
		   numbers[ans]=6;
		   ans++;
	   }
	   if(s[i]=='7'){
		   numbers[ans]=7;
		   ans++;
	   }
	   if(s[i]=='8'){
		   numbers[ans]=8;
		   ans++;
	   }
	   if(s[i]=='9'){
		   numbers[ans]=9;
		   ans++;
	   }
	   //cout<<"ans "<<ans<<endl;        tiaoshi
   }
   sort(numbers,numbers+ans);
   //for(int i=0;i<ans;i++)
      //cout<<numbers[i]<<" "<<i<<endl;
      
      //cout<<s[0];
      //cout<<ans<<endl;
   for(int j=ans-1;j>=0;j--){
	   if(numbers[j]==9){
		   sum+='9';
	   }
	   if(numbers[j]==8){
		   sum+='8';
	   }
	   if(numbers[j]==7){
		   sum+='7';
	   }
	   if(numbers[j]==6){
		   sum+='6';
	   }
	   if(numbers[j]==5){
		   sum+='5';
	   }
	   if(numbers[j]==4){
		   sum+='4';
	   }
	   if(numbers[j]==3){
		   sum+='3';
	   }
	   if(numbers[j]==2){
		   sum+='2';
	   }
	   if(numbers[j]==1){
		   sum+='1';
	   }
	   if(numbers[j]==0){
		   sum+='0';
	   }
	   //cout<<sum<<" "<<j<<endl;
   }
   cout<<sum<<endl;
   return 0;
}
