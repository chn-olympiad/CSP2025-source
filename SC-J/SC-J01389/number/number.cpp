#include<bits/stdc++.h>
using namespace std;
int lenth=0,number[1005],k=0,Max=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	lenth=s.size();
	for(int i=0;i<lenth;i++){
		if(s[i]>=48&&s[i]<=57){
			k++;
			number[k]=s[i];
			number[k]-=48;
			
		}
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=k;i++){
			if(number[i]<number[i+1]) swap(number[i],number[i+1]);
		}
		
	}
	for(int i=1;i<=k;i++) cout<<number[i];
	return 0;
} 