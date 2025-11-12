#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,k;
	cin>>s;
	int b,ans=0;
	b=s.size();
	for(int i=0;i<b;i++){
		if(s[i]>=48&&s[i]<=57){
			k[ans]=s[i];
			ans++;
		}
	}for(int i=ans;i>0;i--){
		for(int j=0;j<ans;j++){
			if(k[j]<k[j+1]){
			swap(k[j],k[j+1]);
			}
		}
	}
	for(int i=0;i<ans;i++){
		cout<<k[i];
	}
return 0;
}

