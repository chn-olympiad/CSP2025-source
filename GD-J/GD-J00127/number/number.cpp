#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	//cout<<n;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]]++;
			//cout<<s[i];
		}
	}
	for(char i='9';i>='0';i--){
		//cout<<a[i]<<" ";
		if(a[i]>0){
			for(int j=1;j<=a[i];j++){
				//cout<<45;
				cout<<i;
			}
			//cout<<787;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
