#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],sum=1,ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    ans=s.size();
    for(int i=0;i<ans;i++){
	    if(s[i]>='0' and s[i]<='9'){
		    a[sum]=s[i]-'0';
		    sum++;
		}	
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>1;i--){
		cout<<a[i];
	}
    return 0;
}
