#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len = s.length();
	for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[s[i] - '0']++;
		}
	}
	bool flag = 0;
	for(int i = 9; i >= 0; i--){
		if(i != 0 && a[i] != 0){
			flag = 1;
		}
		if(flag == 0 && i == 0){
			printf("%d",0);
			break;
		}else{
			while(a[i]--){
				printf("%d",i);
			}
		}
	}
	if(flag){
		cout<<endl;
	}
	return 0;
}
