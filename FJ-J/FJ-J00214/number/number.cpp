#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	int sum=0,b[10005];
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i];
			sum++;
		}else{
			continue;
		}
	}
	for(int i=0;i<sum;i++){
		if(a[i]<a[i+1]){
			a[i]=a[i+1];
			a[i-1]=a[i];	
		}
		else{
			
		}cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
