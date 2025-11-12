#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
string s;
long long idx;
int ans[N];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i = 0;i < n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			idx++;
			ans[idx] = (int)(s[i] - '0');
		}
	}
	sort(ans + 1,ans + 1 + idx,cmp);
	for(int i = 1;i <= idx;i++){
		printf("%d",ans[i]);
	}
	return 0;
}
