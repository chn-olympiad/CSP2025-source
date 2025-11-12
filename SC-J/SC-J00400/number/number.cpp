#include<bits/stdc++.h>
using namespace std;
string s1;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int len=s1.size();
	for(int i=0;i<len;i++){
		if(s1[i]>=48&&s1[i]<=57)a[s1[i]-48]++;
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++)printf("%d",i);
	}
	return 0;
}