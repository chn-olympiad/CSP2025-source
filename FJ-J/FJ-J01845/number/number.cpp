#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 9999999
using namespace std;
string s,ans;
int a[MAX],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	while(a[k-1]==0 && k>1)	k--;
	for(int i=k-1;i>=0;i--) ans+=a[i]+'0';
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
