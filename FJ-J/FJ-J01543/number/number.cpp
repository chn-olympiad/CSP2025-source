#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			k++;
			a[k]=s[i]-48;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--) printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
