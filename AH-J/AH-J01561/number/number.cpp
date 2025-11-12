#include <bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			/*mem*/a[cnt]=s[i]-'0'; 
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
