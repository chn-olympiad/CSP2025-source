#include<bits/stdc++.h>
using namespace std;
string s[1000010],n[10]={"0","1","2","3","4","5","6","7","8","9"};
int a[1010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i=0;
	while(s--){
		for(int j=9;j>=0;j--){
			if(s[i]==n[j]){
				a[i]==int(s[i]);
			}
		}
		i++;
	}
	for(i>=0;i--){
		a[i]=max(a[i],a[i+1]);
	}
	for(i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
