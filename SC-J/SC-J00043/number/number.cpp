/**
 * @file number.cpp 
 * @version: 1.0.0 
 * @author: dpl
 * @date: 2025-11-01 10:39:11
 * 
 **/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int a[1000050],cnt=1;
	for (int i=0;i<=s.size()-1;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for (int i=1;i<cnt;i++){
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}