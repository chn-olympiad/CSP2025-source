#include<bits/stdc++.h>
using namespace std;
int c[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]=='0')c[0]++;
		if(n[i]=='1')c[1]++;
		if(n[i]=='2')c[2]++;
		if(n[i]=='3')c[3]++;
		if(n[i]=='4')c[4]++;
		if(n[i]=='5')c[5]++;
		if(n[i]=='6')c[6]++;
		if(n[i]=='7')c[7]++;
		if(n[i]=='8')c[8]++;
		if(n[i]=='9')c[9]++;
	}
	if(c[9]==0&&c[8]==0&&c[7]==0
	&&c[6]==0&&c[5]==0&&c[4]==0
	&&c[3]==0&&c[3]==0&&c[2]==0
	&&c[1]==0&&c[0]>1){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(c[i]--)cout<<i;
	}
	return 0;
}
