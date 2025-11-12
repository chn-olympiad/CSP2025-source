#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;
			a[i]=s[i]-'0';
			if(a[i]==0){
				b[0]++;
			}else if(a[i]==1){
				b[1]++;
			}else if(a[i]==2){
				b[2]++;
			}else if(a[i]==3){
				b[3]++;
			}else if(a[i]==4){
				b[4]++;
			}else if(a[i]==5){
				b[5]++;
			}else if(a[i]==6){
				b[6]++;
			}else if(a[i]==7){
				b[7]++;
			}else if(a[i]==8){
				b[8]++;
			}else if(a[i]==9){
				b[9]++;
			}
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
	//cout<<"\n99998888887777766666655555544444433332111000000000";
	return 0;
} 
