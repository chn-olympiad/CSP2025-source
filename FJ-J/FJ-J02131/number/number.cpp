#include<bits/stdc++.h>
using namespace std;
int sum[10],n;
string s;
void chore(){
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0')sum[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			printf("%d",i);
		}
	}
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	if(n<=100000){
		for(int i=0;i<n;i++){
			if(s[i]<='9'&&s[i]>='0')sum[s[i]-'0']++;
		}
		for(int i=9;i>=0;i--){
			for(int j=1;j<=sum[i];j++){
				cout<<i;
			}
		}
	}else{
		chore();
	}
	return 0;
}
