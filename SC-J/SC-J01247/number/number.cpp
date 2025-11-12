#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int a[N],c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		a[i]=s[i]-'0';
		if(s[i]>='a'&&s[i]<='z')
			continue;
		c[j]=a[i];
		j++;
	}
	sort(c,c+j);
	for(int i=j-1;i>=0;i--){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}