#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 string a;
 cin>>a;
 int len=a.size();
 for(int i=0;i<len;i++){
 if(isdigit(a[i])){
	 num[a[i]-'0']++;
	 }
	}
 for(int i=9;i>=0;i--){
    while(num[i]--){
      cout<<i;
    }
 }
 fclose(stdin);
 fclose(stdout);
 return 0;
}
