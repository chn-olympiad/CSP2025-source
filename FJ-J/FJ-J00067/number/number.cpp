#include<bits/stdc++.h>
using namespace std;
string str;
bool flag;
int a[15],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	len=str.size();
	for(int i=0;i<len;i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[str[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]){
			if(i!=0){
				flag=1;
			}else{
				if(!flag){
					break;
				}
			}
			while(a[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}
