#include<bits/stdc++.h>
using namespace std;
string s[10000]={0};	
int n[10000]={0};
int main{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num=0;
	for(int i=1;i<10000;i++){
		cin>>s[i];
		if(s[i]<=0){
			continue;
		}
		else{
			for(int j=0;j<10;j++){
				if(int(s[i])==j){
					n[i]=s[i];	
				}
				else{
					continue;
				}
			}
		}
		int maxn=n[i];
		for(int k=0;k<=100;k++){
			if(maxn>n[k+1]){
				continue;
			}
			else{
				maxn=n[k+1];
			}
		}
		num=num*10+maxn;
	}
	cout<<num;

	return 0;
}
