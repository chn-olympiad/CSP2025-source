#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int a[100005];
bool cmp(int x,int y){
	if(x<y)return 0;
	return 1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string s,k=""; 
	cin >> s;
	for(long long i=0;i<(long long)(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=(s[i]-'0');
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout << a[i];
	}
	
    return 0;
}
