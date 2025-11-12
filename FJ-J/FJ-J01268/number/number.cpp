#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char a;
	int sum=0;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[sum]=s[i];
			sum++;
		}
	}
	for(int i=0;i<=sum;i++){
		for(int j=sum;j>=i+1;j--){
			if(a[j]>a[j-1]){
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=0;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
}
