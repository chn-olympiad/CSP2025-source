#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k=0;
	cin>>s;
	char arr[s.length()];
	for(auto i:s){
		if(i<='9'&&i>='0'){
			arr[k++]=i;
		}
	}sort(arr,arr+k,cmp);
	for(int i=0;i<k;i++)cout<<arr[i];
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
