#include <bits/stdc++.h>
using namespace std;
string s;
int ans,c,b[9];
char k[10]={0,1,2,3,4,5,6,7,8,9},a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=s[i];
		c=i;
	}
	c=c+1;
	for(int i=0;i<c;i++){
			if(a[i]=='0') b[0]++;
			if(a[i]=='1') b[1]++;
			if(a[i]=='2') b[2]++;
			if(a[i]=='3') b[3]++;
			if(a[i]=='4') b[4]++;
			if(a[i]=='5') b[5]++;
			if(a[i]=='6') b[6]++;
			if(a[i]=='7') b[7]++;
			if(a[i]=='8') b[8]++;
			if(a[i]=='9') b[9]++;
	}
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
