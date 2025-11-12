#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],j=0,lens,maxi=-1,f;
long long sum=0;
bool vis[10001]={false};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	for(int i=0;i<j;i++){
		maxi=-1;
		for(int k=0;k<j;k++){
			if(a[k]>maxi&&vis[k]==false){
				maxi=a[k];
				f=k;
			}
		}
		vis[f]=true;
		sum=sum*10+maxi;
	}
	cout<<sum;
	return 0;
}
