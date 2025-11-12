#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int j=0,number[n],num=0;
	for(int i=0;i<n;i++){
		if(s[i]-'a'>=0&&s[i]-'a'<26){
		}else{
			number[j]=s[i]-'0';
			j++;
		}
	}
	number.sort(4,8);
	for(int i=0;i<j;i++){
		for(int k=i;k<j;k++){
			if(number[i]<number[k]){
				num=number[k];
				number[k]=number[i];
				number[i]=num;
			}
		}
	}
	for(int i=0;i<j;i++){
		cout<<number[i];
	}
    return 0;
}

