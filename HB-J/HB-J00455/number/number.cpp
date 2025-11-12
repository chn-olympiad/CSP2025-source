#include<bits/stdc++.h>
using namespace std;
string x;
long long num[15];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	cin>>x;
	int len=x.size();
	for(int i=0;i<len;i++){
		if(x[i]>='0'&&x[i]<='9'){
			num[x[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			printf("%d",i);
			num[i]--;
		}
	}
    return 0;
}
