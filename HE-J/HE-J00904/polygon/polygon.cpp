#include<iostream>
using namespace std;
string s,num;
int cnt=0,c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]+0>=48&&s[i]+0<=57){
			num[cnt]=s[i];
			cnt=cnt+1;
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			if(num[j]>num[i]){
				c=num[i];
				num[i]=num[j];
				num[j]=c;
				c=0;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
