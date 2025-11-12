#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	if (a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0){
		cout<<'0';
	}
	else{
		for (int i=9;i>=0;i--){
			while(a[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}
//RP++
