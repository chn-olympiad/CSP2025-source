#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 1e6+5;

string a;
int rs[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			rs[a[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=rs[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
