#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<=n;i++){
		if(s[i]>='0' && s[i]<='9'){
			int b=s[i]-'0';
			a[b]++;
		}
	}
	for(int j=9;j>=0;j--){
		if(a[j]!=0){
			while(a[j]){
				cout<<j;
				a[j]--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
