#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[1000010],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	stable_sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
