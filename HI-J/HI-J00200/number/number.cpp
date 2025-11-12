#include<bits\stdc++.h>
using namespace std;
string str;
int cnt[15],num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(isdigit(str[i])) cnt[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(cnt[i]!=0){
			num++;
			if(num==1&&i==0) cout<<0;
			else{
				for(int j=1;j<=cnt[i];j++){
					cout<<i;
				}
			}
		}
	}
	return 0;
}

