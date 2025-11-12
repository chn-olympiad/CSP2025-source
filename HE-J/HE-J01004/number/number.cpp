#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	   for(int i=0;i<=a;i++){
	   if(s[i]>='0'&&s[i]<='9'&&a!=1){
 if(s[i]>=s[i+1]){
		cout<<s[i];	
     }
     else if(s[i]<s[i+1]){
	swap(s[i],s[i+1]);
cout<<s[i];	
	}			
		}
		else{
		cout<<s[i];
			}	

}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
