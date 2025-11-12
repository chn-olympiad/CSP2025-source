#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++] = s[i]-'0';
		}
	}sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--)
		printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//效率慢，过不了number/number4测试点。 