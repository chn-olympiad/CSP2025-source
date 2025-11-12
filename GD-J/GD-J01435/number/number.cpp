#include<bits/stdc++.h> 
using namespace std;
string n;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		a[n[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		int t=a[i];
		while(t--){
			cout<<i;
		}
	}
	return 0;
}

