#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10]={};
	int i,j;
	cin>>s;
	for(i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]+=1;
		}
	}
    for(i=9;i>=0;i--){
    	if(a[i]>0){
    		for(j=1;j<=a[i];j++){
    			cout<<i;
			}
		}
	}
	return 0;
}