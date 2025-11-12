#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in.txt","r",stdin);
	freopen("number.out.txt","w",stdout);
	string s;
	cin>>s;
	int num[s.size()+5],k=0;
	for(int i=0;i<=s.size();i++){
		if(int(s[i])>=48 && int(s[i])<=57){
			num[k+1]=int(s[i])-48;
			k++;
		}
	}
	sort(num+1,num+k+1);
	for(int i=k;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}

