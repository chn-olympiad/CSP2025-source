#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int n,s[1000010],c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]>=48&&a[i]<=57){
			c++;
			s[c]=int(a[i])-48;
		}
	}
	sort(s+1,s+c+1,cmp);
	for(int i=1;i<=c;i++){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
