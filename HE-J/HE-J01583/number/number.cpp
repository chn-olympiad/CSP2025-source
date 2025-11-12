#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),j=1;
	for(int i=0;i<=l;i++){
		if(s[i]>=48&&s[i]<=57){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<j;i++){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
