#include<bits/stdc++.h>
using namespace std;

string str;
int size_arr;
int arr[1000005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,str);
	for(int i=0;i<str.size();i++){
		if(isdigit(str[i])){
			size_arr++;
			arr[size_arr]=str[i]-'0';
		}
	}
	sort(arr+1,arr+size_arr+1,cmp);
	for(int i=1;i<=size_arr;i++){
		cout<<arr[i];
	} 
	return 0;
}
