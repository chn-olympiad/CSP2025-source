#include<bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4
using namespace std;
string s;
int tot=0;
char x[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0' && s[i]<='9') x[++tot]=s[i];
	}
	sort(x+1,x+tot+1);
	bool f=false;
	for(int i=tot;i>=1;i--) {
		if(x[i]=='0'){
			if(f==true || i==1) cout<<x[i];
		
		}
		else {
			f=true;
			cout<<x[i];	
		}	
	}
	return 0;
} 
