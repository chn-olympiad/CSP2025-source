#include<bits/stdc++.h>
using namespace std;
string s,z;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int b=0;
	cin>>s;
	for(int i=0;i<=10086;i++){
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' ){
			z[b]=s[i];
			b++; 
		}
		if(s[i]=='0') break;
	}
	for(int i=0;i<=b-1;i++){
		for(int j=i+1;j<=b-1;j++){
		    if(z[i]<=z[j]){
			    int t=z[i];
			    z[i]=z[j];
			    z[j]=t;
		    }
		}
	}
	for(int i=0;i<=b-5;i++){
		cout<<z[i];
	}
	return 0;
}