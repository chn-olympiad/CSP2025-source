#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
	string s;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]=='0'){
			ans[0]=ans[0]+1;
		}
		else if(s[i]=='1'){
			ans[1]=ans[1]+1;
		}
		else if(s[i]=='2'){
			ans[2]=ans[2]+1;
		}
		else if(s[i]=='3'){
			ans[3]=ans[3]+1;
		}
		else if(s[i]=='4'){
			ans[4]=ans[4]+1;
		}
		else if(s[i]=='5'){
			ans[5]=ans[5]+1;
		}
		else if(s[i]=='6'){
			ans[6]=ans[6]+1;
		}
		else if(s[i]=='7'){
			ans[7]=ans[7]+1;
		}
		else if(s[i]=='8'){
			ans[8]=ans[8]+1;
		}
		else if(s[i]=='9'){
			ans[9]=ans[9]+1;
		}
	}
	for(int i=9;i>=0;i--){
		if(ans[i]>0){
			for(int l=0;l<ans[i];l++){
				cout<<i;
			}
		}
	}
	return 0;
}
