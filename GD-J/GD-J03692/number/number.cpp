//RP+++++++++++++++++++++++++;
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len =s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}else{
			a[i]=-1;
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--){
		if(a[i]==-1) break;
		cout << a[i];
	}
	return 0;
}
