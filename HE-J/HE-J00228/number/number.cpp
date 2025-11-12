#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[10]={0};
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')b[a[i]-'0']++;
	}
	int flag=0
	for(int i=9;i>=1;i--)if(b[i]>0)flag=1;
	if(flag!=0){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=b[i];j++){
				cout<<i;
			}
		}
	}else cout<<0;
	
	return 0;
}
