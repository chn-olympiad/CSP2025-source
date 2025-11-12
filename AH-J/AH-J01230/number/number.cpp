#include<bits/stdc++.h>
using namespace std;
string ss;
char a[1000005];
int aa;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	for(unsigned int i=0;i<ss.size();i++)
		if(ss[i]>='0'&&ss[i]<='9')
			a[++aa]=ss[i];
	sort(a+1,a+aa+1);
	for(int i=aa;i>=1;i--)
		cout<<a[i];
	return 0;
}
