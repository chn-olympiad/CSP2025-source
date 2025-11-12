#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
string s;
int a[MAXN],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++l] = s[i] - '0';
		}
	}
	
	sort(a+1,a+l+1);
	
	for(int i=l;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}

