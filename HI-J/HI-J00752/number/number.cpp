#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int a[100005];
string s;
int k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
	if(s[i]>='0'&&s[i]<='9'){
	a[k]=int(s[i])-48;
	k++;
	}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<k;i++){
	printf("%d",a[i]);
	}
	return 0;
}