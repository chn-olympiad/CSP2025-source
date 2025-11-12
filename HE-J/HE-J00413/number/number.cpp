#include<bits/stdc++.h>
using namespace std;
int b[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int a=str.size();
	
	if(a==1){
		cout<<str;
	}else{
		int k=1;
		for(int i=0;i<a;i++){
			if(str[i]>='0'&&str[i]<='9'){
				b[k]=str[i]-'0';
				k++;
			}
		}
		sort(b,b+k);
		for(int i=k-1;i>0;i--){
			cout<<b[i];
		}
	}
	
	return 0;
} 
