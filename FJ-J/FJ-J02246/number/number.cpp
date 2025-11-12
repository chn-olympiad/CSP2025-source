#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S;
	cin>>S;
	int a[15]={0};
	for(int i=0;i<S.size();i++){
		if(S[i]>='0'&&S[i]<='9')a[S[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}		
	}
	return 0;
} 
