#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	
	int arr[len];
	int j=-1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			j++;
			arr[j]=s[i]-'0';
			
		}
	}
	sort(arr,arr+j+1);
	for(int i=j;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
} 
