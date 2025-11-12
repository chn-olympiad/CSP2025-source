#include<fstream>
#include<string>
#include<cstdio>
using namespace std;
ifstream cin("number.in");
ofstream cout("number.out");
string work(string str){
	string ans="";
	int nums[10]={};
	int str_size=str.size();
	for(int i=0;i<str_size;i++){
		if(0<=str[i]-'0'&&str[i]-'0'<=9){
			nums[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(nums[i]>0){
			ans+=char(i+'0');
			nums[i]--;
		}
	}
	return ans;
}
int main(){
	string s;
    cin>>s;
    cout<<work(s);
    return 0;
}
