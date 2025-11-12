#include <iostream>
using namespace std;
const int MAXN=15;
int a[MAXN];
int main(){
	
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int temp=s[i]-'0';
			a[temp]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
} 
