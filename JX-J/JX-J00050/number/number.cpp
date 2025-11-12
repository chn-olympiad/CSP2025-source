#include<bits/stdc++.h>
using namespace std;
int p[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			p[s[i]-'1'+1]++;
		}
	}
	int sum=0;
	for(int i=9;i>=0;i--){
		if(p[i]!=0){
			for(int j=1;j<=p[i];j++){
				sum=sum*10+i;
			}
		}
	}
	cout<<sum;
	return 0;
}
