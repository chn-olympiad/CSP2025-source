#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+3;
char str[N];
int len;
int mount[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	len = strlen(str);
	for(int i=0;i<len;i++){
		if('0'<=str[i] && str[i]<='9'){
			mount[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(mount[i]>0){
			for(int j=1;j<=mount[i];j++){
				cout << i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
