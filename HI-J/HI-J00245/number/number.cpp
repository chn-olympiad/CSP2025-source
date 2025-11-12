#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin>>s;
	int lens=s.length();
	for(int i=0;i<=lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[cnt]=int(s[i])-48;
			cnt++;
		}
	}
	sort(arr,arr+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<arr[i];
	}
	return 0;
}
