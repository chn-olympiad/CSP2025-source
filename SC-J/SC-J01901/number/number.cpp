#include<bits/stdc++.h>
using namespace std;
char b[100005];
string s;
int k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			b[k]=s[i];
			k++;
		}
	}
	sort(b,b+k);
	for(int i=k-1;i>=0;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}