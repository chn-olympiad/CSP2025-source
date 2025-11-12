#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={0};
	int g=s.size();
	for(int i=0;i<g;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[s[i]-'0']+=1;
		}
	}
	int m=0;
	for(int j=9;j>=0;j--){
		if(a[j]>0){
			for(int k=a[j];k>0;k--){
				m=m*10+j;
			}
		}
	}
	cout<<m<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
