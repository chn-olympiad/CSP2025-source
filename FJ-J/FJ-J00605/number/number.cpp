#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10];
	memset(a,0,sizeof(a));
	for(int i=0;i<s.size();i++){
		if(47<s[i]&&s[i]<58){
			a[int(s[i])-'0']++;
		}
	}
	if(a[0]>1&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0){
		cout<<0;
	}
	else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}