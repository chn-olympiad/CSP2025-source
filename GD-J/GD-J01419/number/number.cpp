#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
bool vis[1000005]={0};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.length(),l=0;
	for(int i=0;i<len;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<10){
		   	l++;
		}
	}
	for(int j=1;j<=l;j++){
	   for(int i=0;i<len;i++){
		  if(s[i]-'0'>=0&&s[i]-'0'<10){
		  	if(vis[i]==0){
		  		a[j]=s[i]-'0';
		  		vis[i]=1;
		  		break;
			  }
		  }
	}
}
   sort(a,a+l+1);
   for(int i=l;i>0;i--){
   	  cout<<a[i];
   }
	return 0;
}
