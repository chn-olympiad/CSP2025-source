#include<bits/stdc++.h>
using namespace std;
int d[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000001];
	int b=s.size();
	int c=0;
	for(int i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c++;
			a[c]=s[i]-'0';	
		}
	}
	for(int i=1;i<=c;i++){
		d[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		if(d[i]>0){
			for(int j=1;j<=d[i];j++){
				cout<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
