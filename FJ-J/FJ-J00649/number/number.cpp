#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0' && a[i]<='9')  num[a[i]-'0']++;
	}for(int i=9;i>=0;i--){
		if(num[i]!=0){
			for(int j=1;j<=num[i];j++)  cout<<i;
		}
	}return 0;
} 
