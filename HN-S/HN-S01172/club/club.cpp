#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,s[3*n+5]={},sum=0;
	cin>>n;
	for(int i=1;i<=n*3+5;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i+=3){
		if(s[i]>s[i+1]&&s[i]>s[i+2]){
			sum+=s[i];
		}
		if(s[i+1]>s[i]&&s[i+1]>s[i+2]){
			sum+=s[i+1];
		}
		if(s[i+2]>s[i+1]&&s[i+2]>s[i]){
			sum+=s[i+2];
		}
		if(s[i]=s[i+1]&&s[i]>s[i+2]){
			sum+=s[i];
		}
		if(s[i]=s[i+2]&&s[i]>s[i+1]){
			sum+=s[i];
		}
		if(s[i+2]=s[i+1]&&s[i+2]>s[i]){
			sum+=s[i+2];
		}
		if(s[i]=s[i+1]&&s[i]==s[i+2]){
			sum+=s[i+1];
		}
	}
	cout<<sum;
	return 0;
}

