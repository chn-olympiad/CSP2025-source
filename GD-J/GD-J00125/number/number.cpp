#include <iostream>
#include <cstdio>

using namespace std;

string s;
int t[10],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&cnt==0)cout<<0;
		else{
			while(t[i]!=0){
				cout<<i;
				t[i]--; 
				cnt++;
			}	
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
