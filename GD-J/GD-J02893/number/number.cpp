#include<bits/stdc++.h>
using namespace std;
const int N=1e6+500;
int t[12];
string st;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	for(int i=0;i<=st.length();i++){
		if('0'<=st[i]&&st[i]<='9'){
			t[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		//cout<<t[i];
		if(t[i]>0){
			for(int j=1;j<=t[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}
