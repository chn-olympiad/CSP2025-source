#include<bits/stdc++.h>
using namespace std;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	
	int flag=0;
	for(int i=9;i>=0;i--){
		if(i!=0){
			if(t[i]>0){
				flag=1;
				for(int j=1;j<=t[i];j++){
					cout<<i;
				}
			}
		}else{
			if(flag==1){
				for(int j=1;j<=t[i];j++){
					cout<<i;
				}
			}else{
				cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
