#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char shu[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long k=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			shu[k]=s[i];
			k++;
		}
	}
	sort(shu+1,shu+1+k);
	for(int i=k;i>=1;i--){
		cout<<shu[i];
	}
	return 0;
}

