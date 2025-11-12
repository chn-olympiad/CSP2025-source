#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	int i;
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<(int)(s.length());i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(i=9;i>=0;i--)while(a[i]>0){
		cout<<i;
		a[i]--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
