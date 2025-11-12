#include<bits/stdc++.h>
using namespace std;
string s;
int a[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>=48&&s[i]<=58){
			a[s[i]-48]++;
		}
	}
	int sum=0;
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			if(a[i]!=0){
				sum=sum*10+i;	
			}	
		}
	}
	cout<<sum;
	return 0;
}
