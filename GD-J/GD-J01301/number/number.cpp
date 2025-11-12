#include<bits/stdc++.h>
using namespace std;
string s;
int lens;
int arr[100001];
int temp=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]-48>=0&&s[i]-48<=10){
			arr[temp]=int(s[i])-48;
			temp++;
		}
	}
	sort(arr+1,arr+temp);
	for(int i=temp-1;i>=1;i--){
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
