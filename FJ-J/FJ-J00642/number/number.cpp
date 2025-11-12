#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int answer[1000005];
int main(){
	freopen("number.in","w",stdin); 
	freopen("number.out","r",stdout);
    char a;
    long long  b,ans=0;
    string str;
    cin>>str;
   long long l=str.size();
    for(int i=0;i<=1000000;i++){
    num[i]=-1;
}
    for(int i=0;i<l;i++){
    	if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'||str[i]=='0'){
		a=str[i];
		b=int(a)-48;
		ans++;
		num[i]=b;
	}
}
sort(num+0,num+l+1);
for(int i=l;i>=0;i--){
if(num[i]!=-1)
cout<<num[i];
}
	return 0;
}	
