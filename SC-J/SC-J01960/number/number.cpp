#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10];
	string s;
	cin>>s;
	memset(a,0,sizeof(a));
	int i,j,n=s.size();
	for(i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=a[i];j>0;j--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}