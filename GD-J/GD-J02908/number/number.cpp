#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[1000]={0};
	cin>>a;
	int n=a.length();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9')b[a[i]]++;
	}for(int i='9';i>='0';i--){
		for(int j=1;j<=b[i];j++){
			cout<<i-'0';
		}
    }
}
