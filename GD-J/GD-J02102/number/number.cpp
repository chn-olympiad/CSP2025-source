#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<n.size();i++){
		if(n[i]<='9'&&n[i]>='0'){
			a[++cnt]=n[i]-'0';
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<a[i];
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
