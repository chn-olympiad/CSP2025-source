#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	getline(cin,str);
	int t=str.size();
	int a[t+5]={0};
	int cnt=0;
	for(int i=0;i<t;i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[i]=str[i]-'0';
			if(a[i]==0){
				cnt++;
			}
		}
	}
    sort(a,a+t+5);
    for(int i=t+5;i>0;i--){
    	if(t==1){
    		cout<<a[i];
		}else{
			if(a[i]==0&&cnt>0){
				cnt--;
			}else{
				break;
			}
			cout<<a[i];
		}
	}
	return 0;
} 
