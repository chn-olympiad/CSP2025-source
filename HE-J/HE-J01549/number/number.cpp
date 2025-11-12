#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int f[10]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f[0]+=1;
		}
		else if(s[i]=='1'){
			f[1]+=1;
		}
		else if(s[i]=='2'){
			f[2]+=1;
		}
		else if(s[i]=='3'){
			f[3]+=1;
		}
		else if(s[i]=='4'){
			f[4]+=1;
		}
		else if(s[i]=='5'){
			f[5]+=1;
		}
		else if(s[i]=='6'){
			f[6]+=1;
		}
		else if(s[i]=='7'){
			f[7]+=1;
		}
		else if(s[i]=='8'){
			f[8]+=1;
		}
		else if(s[i]=='9'){
			f[9]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=f[i];j++){
			cout<<i;
		}
	}
}
