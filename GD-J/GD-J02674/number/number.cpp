#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k = 0;
	for (int i=0;i<s.size();i++){
		if(!(s[i]>='a' && s[i]<='z')){
			k++;
			num[k] = int(s[i])-48;
		}
	}
	
	sort(num+1,num+k+1);
	for  (int i=k;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
