#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int t,a[N];
//Ï£ÍûÄÜ¹ýºÙºÙºÙ 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=s.size();
	while(l--){
		if(isdigit(s[l])){
			t++;
			a[t]=s[l]-'0';
		}
	}
	sort(a+1,a+1+t,greater<int>());
	for(int i=1;i<=t;i++){
		cout << a[i];
	}
    return 0;
}
