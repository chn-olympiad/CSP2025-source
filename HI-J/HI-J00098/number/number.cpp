#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int a=1,x;
	string s,c[10001],b[10001],max;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
			c[a]=s[i];
			a=a+1;
	}
	for(int j=1;j<=s.size();j++){
	max=c[1];
	for(int i=1;i<=s.size();i++){
		if(max<c[i+1])
			c[i]=c[i+1];
			c[i+1]=max;
			//b[i]=c[i+1];
			//b[i+1]=max;
			
		//if(max<c[i+1])
			//max=c[i+1];
	}
}
	//cout<<max;
	for(int i=1;i<=s.size();i++){
		cout<<c[i];
	}
return 0;
}
