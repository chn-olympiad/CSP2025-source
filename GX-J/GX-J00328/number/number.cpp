#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
    
    string s;
    cin>>s;
    long long int k=0;
    long long int n;
    for(int i=0;i<s.size();i++){
		 if(s[i]-'0'>=0 and 9>=s[i]-'0'){
			 a[k]=s[i]-'0';
			 k++;
			 }
		}
	sort(a,a+k+1);
	for(int i=k;i>0;i--){
		cout<<a[i];
	}
	
   
  fclose(stdin);
  fclose(stdout);

    return 0;
}
