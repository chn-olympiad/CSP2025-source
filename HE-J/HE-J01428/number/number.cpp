#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool smp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int u=0,a=0;
	short o[N];
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			
			o[u]=s[i]-'0';
			u++;
		}
	}
	sort(o,o+u,smp);
	for(int i=0;i<u;i++)
		cout<<o[i];
	

	return 0;
}
