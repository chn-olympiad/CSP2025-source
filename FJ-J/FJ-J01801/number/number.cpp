#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000000;
string s;
int num[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	int n;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n++]=s[i]-'0';
		}
	}
	sort(num,num+n);
	for(int i=n-1;i>=0;i--){
		printf("%d",num[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
