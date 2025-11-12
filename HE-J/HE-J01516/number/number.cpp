#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	string s;
	int a[100001];
	cin>>s;
	int i=0,j=0;
	while(s[i]>='0'&&a[i]<='z'){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
		i++;
	}
	for(int i=1;i<j;i++){
		for(int s=0;s<j-1;s++){
			if(a[s]<=a[i]){
				swap(a[s],a[i]);
			}
		}
	}
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
