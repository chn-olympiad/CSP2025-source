//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int a[205];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s9;
	cin>>s9;
	int n=s9.size()-1,b;
	for(int i=0;i<=n;i++){
		b=int(s9[i])-'0';
		if(b>=0&&b<=9){
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
