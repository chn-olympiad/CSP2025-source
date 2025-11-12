#include<bits/stdc++.h>
using namespace std;
char s[1000009];
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]==0) break;
		if(s[i]-'0'==0){
			a[0]++;
			a[1]++;
		}
		if(s[i]-'0'==1){
			a[0]++;
			a[2]++;
		}
		if(s[i]-'0'==2){
			a[0]++;
			a[3]++;
		}
		if(s[i]-'0'==3){
			a[0]++;
			a[4]++;
		}
		if(s[i]-'0'==4){
			a[0]++;
			a[5]++;
		}
		if(s[i]-'0'==5){
			a[0]++;
			a[6]++;
		}
		if(s[i]-'0'==6){
			a[0]++;
			a[7]++;
		}
		if(s[i]-'0'==7){
			a[0]++;
			a[8]++;
		}
		if(s[i]-'0'==8){
			a[0]++;
			a[9]++;
		}
		if(s[i]-'0'==9){
			a[0]++;
			a[10]++;
		}
	}
	for(int i=10;i>0;){
		if(a[i]==0){
			i--;
			continue;
		}
		cout<<i-1;
		a[i]--;
	}
	return 0;
}

