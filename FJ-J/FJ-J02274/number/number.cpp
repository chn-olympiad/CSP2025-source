#include<bits/stdc++.h>
using namespace std;
string str;
int num[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0')num[0]++;
		else if(str[i]=='1')num[1]++;
		else if(str[i]=='2')num[2]++;
		else if(str[i]=='3')num[3]++;
		else if(str[i]=='4')num[4]++;
		else if(str[i]=='5')num[5]++;
		else if(str[i]=='6')num[6]++;
		else if(str[i]=='7')num[7]++;
		else if(str[i]=='8')num[8]++;
		else if(str[i]=='9')num[9]++;
	}for(int i=9;i>=0;i--){
		while(num[i]--){
			cout<<i;
		}
	}
	return 0;
} 
