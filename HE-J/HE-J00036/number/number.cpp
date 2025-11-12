#include<iostream>
#include<string>
using namespace std;
const int a=1e6;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int q=s.size();
	char arr[a];
	if(q==1){
		cout<<s;
		return 0;
	}
	char t[a];
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			arr[i]=s[i];
		}else{
			t[i]=s[i];
		}
	}
	for(int m=0;m<q;m++){
		for(int j=0;j<q-m-1;j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(int z=0;z<q;z++){
		cout<<arr[z];
	}
	return 0;
}


