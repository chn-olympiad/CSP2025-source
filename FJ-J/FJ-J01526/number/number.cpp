#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int m=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
		int a=s[i]-'0';
		arr[m]=a;
		m+=1;
	}
	sort(arr+1,arr+m+1,cmp);
	for(int i=1;i<m;i++){
		cout<<arr[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
