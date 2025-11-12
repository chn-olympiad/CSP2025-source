#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000010];
int brr[1000010];
int ans;
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<'A'){
			arr[i]=s[i]-'0';
			ans++;
		}
	}
	sort(arr,arr+s.size(),cmp);
	for(int i=0;i<ans;i++){
		cout<<arr[i];
	}
}
