#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char a[1005];
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int ind=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ind++;
			a[ind] = s[i];
		}
	}
	sort(a+1,a+ind+1,cmp);
	for(int i=1;i<=ind;i++) cout<<a[i];
	return 0;
}
