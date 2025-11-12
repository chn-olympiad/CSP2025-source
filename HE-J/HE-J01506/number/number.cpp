#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	for(int i=1;i<=s.size();i++){
		cin>>s[i];
	}
    for(int i=1;i<=s.size();i++){
       if(s[i]='1') a[1]+=1;
       else if(s[i]='2') a[2]+=1;
       else if(s[i]='3') a[3]+=1;
       else if(s[i]='4') a[4]+=1;
       else if(s[i]='5') a[5]+=1;
       else if(s[i]='6') a[6]+=1;
       else if(s[i]='7') a[7]+=1;
       else if(s[i]='8') a[8]+=1;
       else if(s[i]='9') a[9]+=1;
       else if(s[i]='0') a[0]+=1;
	}
	for(int i=9;i<=0;i--){
		if(a[i]==1) cout<<a[i];
		else if(a[i]>1){
		while(a[i]!=0){
			cout<<a[i];
			a[i]-=1;
		}	
	}else continue;
	}
	return 0;
}














