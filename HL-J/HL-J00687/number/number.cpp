#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int k = -1;
string s;
int ans[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i] - 'z' < 48){
				ans[k++] = s[i];
		}
	}
	sort(ans,ans+k,cmp);
	for(int i=0;i<k;i++){
		cout << ans[i];
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

