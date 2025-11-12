#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
	    if(s[i]>='0' && s[i]<='9')
	       cnt[s[i]-'0']++;
	}
    bool f=1;
    for(int i=9;i>=0;i--){
	   if(i!=0){
		   if(cnt[i]!=0){
		     f=0;
		     for(int j=1;j<=cnt[i];j++)
		         cout<<i;
			 }
		   }
		  else {
			  if(f){
			      cout<<0;
			      return 0;
			  }
			  else{
				  for(int j=1;j<=cnt[i];j++)
				      cout<<i;
				  }
	}
}
    return 0;
}
