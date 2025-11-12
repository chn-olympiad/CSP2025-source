//gitxiaozheng
//rp++!
#include<bits/stdc++.h>
using namespace std;


int aaasz[10];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		char zifu=str[i];
		if(zifu>='0'&&zifu<='9'){
			aaasz[zifu-'0']++;
		}
	} 
	for(int i=9;i>=0;i--){
		if(aaasz[i]>0){
			for(int j=1;j<=aaasz[i];j++){
				cout<<i;
			}
		}
	}
	
	return 0;
}
