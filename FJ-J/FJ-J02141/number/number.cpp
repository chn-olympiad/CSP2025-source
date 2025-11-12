#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;
	int n=0;
	cin>>s;
	for(char c:s){
		if(isdigit(c))a[n++]=c-'0';
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)cout<<a[i];
	return 0;
}
