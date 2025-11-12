#include<bits/stdc++.h>
using namespace std;
char s[1000];
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int l=s.size(s);
	int cnt=1;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-48;
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i;i<=cnt;j++){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=cnt;i++)printf("%d",a[i]);
	return 0;
}
