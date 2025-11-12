#include<bits/stdc++.h>
using namespace std;
string s;
long long a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i< n ;i++){
		int x=s[i]-'0';
		if((x>=0)&&(x<=9)){
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
