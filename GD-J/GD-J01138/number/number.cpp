#include <iostream>
using namespace std;
char s[1000007];
int num[20]={0};


int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0' && s[i]<='9'){
			num[s[i]-'0']++;
			cnt++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}cout<<endl;
	
	return 0;
} 
