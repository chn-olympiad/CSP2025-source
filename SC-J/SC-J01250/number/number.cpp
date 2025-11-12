#include<bits/stdc++.h>
using namespace std;
int j = 0,ans;
char a[1005];
string s,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>> s;
	for(int i = 0; i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			j++;
			a[j] = s[i];		
		}
	}
	sort(a+1,a+j+1);
	for(int i = j; i > 0; i--){
		c += a[i];
	}
	cout<< c;
	return 0;
}