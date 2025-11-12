#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<math.h>

using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	string resh;

	cin>>str;
	for(int i=0;i<=str.size()-1;i++){
		if(str[i]<='9'&&str[i]>='0'){
			resh+=str[i];
		}
	}
	for(int i=0;i<=resh.size()-1;i++){
		for(int j=0;j<=resh.size()-1;j++){
			if(resh[i]>resh[j]){
				swap(resh[i],resh[j]);
			}
		}
	}
	cout<<resh;
	return 0;
} 