#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int num[100000]={0},pos=0;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			num[pos]=n[i]-'0';
			pos++;
		}
	}
	sort(num,num+pos,greater<int>());
	for(int i=0;i<pos;i++)cout<<num[i];
} 
