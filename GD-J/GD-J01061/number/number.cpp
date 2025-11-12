#include<cstdio>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int a[1000002];

int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","w",stdout);
	
	string n;
	cin>>n;
	int l=n.length();
	int j=0;
	for(int i=0;i<l;i++){
		if(n[i]-'0'<=9&&n[i]-'0'>=0){
			a[j]=n[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
