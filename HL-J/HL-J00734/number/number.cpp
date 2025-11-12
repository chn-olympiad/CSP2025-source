#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
char s[1005];
char k[1005];
bool a(int q,int w){
	 return q<w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=n;i++){
		cin>>s[i];
		if(s[i]>=0&&s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9){
		   	    k[i]=s[i];
				
	        }
	    }
		sort(k+n,k+n+1,a);
		for(int j=0;j<=n;j++)
		{
		    ans++;
		    k[j]-=k[j-1];
		    if(k[j]>=0){
		       cout<<k[j];
			}		
	}
	return 0;
}
