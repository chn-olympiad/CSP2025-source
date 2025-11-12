#include<bits/stdc++.h>
using namespace std;
int f[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(f,f+j);
	for(int i=j-1;i>=0;i--){
		cout<<f[i];
	}
	return 0;
}
//AFO???