#include <bits/stdc++.h>
using namespace std;
string s;
int a[101000],y;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') a[++y]=s[i]-'0';
	}
	sort(a+1,a+y+1);
	for(int i=y;i>=1;i--) printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
