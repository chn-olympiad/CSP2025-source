#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int a[5005];
	memset(a,0,sizeof(a));
	cin >> n;
	for(int i = 0;i < n.length();i++){
		a[n[i]-'0']++;
	}
	for(int i = 9;i >= 0;i--){
		while(a[i]>0){
			cout << i;
			a[i]--;
		}
	}
	return 0;
	//#Shang4Shan3Ruo6Shui4
} 
