#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	int a[500000]={0};
	string s;
	cin>>s;

	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>=48&&s[i]<=57){
			a[k]=s[i]-'0';
			k++;
		}
	}
	while(k--){
		int m=0,q=0;
		for(int i=0;i<=s.size()-1;i++){
			if(a[i]>m){
				m=a[i];
				q=i;
			}
		}
		cout<<m;
		a[q]=0;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
