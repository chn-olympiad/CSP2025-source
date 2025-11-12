#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	char num[100005];
	int j=0;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]<='9'&&a[i]>='0'){
			num[j]=(a[i]);
			j++;
		}
	}
	sort(num,num+j);
	for(int i=j-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
