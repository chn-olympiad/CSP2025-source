#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size()-1;
	
	while(n>=0){
		int p=s[n]-'0';
		if(p>=0&&p<=9){
			a[p]++;
		}
		n--;
	}
	
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(long long j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	
	cout<<endl;
	
	return 0;
}
