#include<bits/stdc++.h>
using namespace std;

string s;
long long a,f,k[1000005]; 

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			k[f]=s[i]-'0';
			f++;
		}
	}
	sort(k,k+f);
	for(int i=f-1;i>=0;i--){
		cout<<k[i];
	}
	
	//#Shang4Shan3Ruo6Shui4
	
	
	return 0;
}
