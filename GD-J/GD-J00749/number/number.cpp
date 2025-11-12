#include<bits/stdc++.h>
using namespace std;

string s1;
long long a[11];
bool b=true;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int cnt=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[s1[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0&&i!=0){
			b=false;
		}
		else if(i==0&&b){
			cout<<0;
			continue;
		}
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
