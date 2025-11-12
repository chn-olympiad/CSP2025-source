#include<bits/stdc++.h>
using namespace std;
string s;
int u,arr[100005];
bool cmp(int a,int b){
	if(a!=b){
		return a>b;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr[u]=int(s[i]-'0');
			u++;
		}
	}
	sort(arr,arr+u,cmp);
	for(int i=0;i<u;i++){
		cout<<arr[i];
	}
	return 0;
}
