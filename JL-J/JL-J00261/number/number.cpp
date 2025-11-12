#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int arr[1000000],x=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[x]=s[i]-'0';
			x++;
		}
	}
	sort(arr,arr+x+1);
	for(int i=x;i>=1;i--){
		cout<<arr[i];
	}
	return 0;
}
