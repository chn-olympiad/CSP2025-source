#include<bits/stdc++.h>
using namespace std;
string str;
int bj[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if('0'<=str[i]&&str[i]<='9')bj[str[i]-'0']++;
	}
	int BJ=1;
	for(int i=9;i>=0;i--){
		if(bj[i]>0&&i>0){
			BJ=0;
			for(int j=1;j<=bj[i];j++)cout<<i;
		}
		else if(i==0&&bj[i]>0){
			if(BJ==1)cout<<0;
			else{
				for(int j=1;j<=bj[i];j++)cout<<i;
			}
		}
	}
	return 0;
}
