#include<bits/stdc++.h>
using namespace std;
char s;
int sl[10];
int len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(~scanf("%c",&s)){
//		len++;
		if(s>='0'&&s<='9'){
			sl[s-'0']++;
			len++;
//			cout<<(s-'0')<<endl;
		}
		
	}
	for(int i = 9;i>=1;i--){
		if(sl[i]){
			for(int j = 1;j<=sl[i];j++){
				cout<<i;
			}
			
			
		}
		
	}
	for(int i = 1;i<=sl[0];i++){
		cout<<'0';
	}
//	cout<<len;
	return 0;
} 
