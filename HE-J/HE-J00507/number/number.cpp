#include <bits/stdc++.h>
using namespace std;
int a[1000050],i;
int main(){
	i=1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int j=0;j<s.size();j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[i]=s[j]-'0';
			//cout<<a[i]<<endl;
			i++;
		}
	}
	sort(a+1,a+i+1);
	for(int k=i;k>1;k--){
		cout<<a[k];
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
