#include<bits/stdc++.h>
using namespace std;
string s;
long long q[10000005];
int k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()+1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q[k]=s[i];
			k++;
		}
	}
	sort(q+1,q+k+1);
	for(int i=k;i>=2;i--){
		cout<<q[i]-'0';
	}
	return 0;
}
