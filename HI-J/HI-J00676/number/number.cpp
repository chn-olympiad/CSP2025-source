#include<bits/stdc++.h>
using namespace std;
int num[100];
string shu[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	shu[0]="0";
	shu[1]="1";
	shu[2]="2";
	shu[3]="3";
	shu[4]="4";
	shu[5]="5";
	shu[6]="6";
	shu[7]="7";
	shu[8]="8";
	shu[9]="9";
	string n,c;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]=='0'){
			num[0]++;	
		}
		if(n[i]=='1'){
			num[1]++;
		}
		if(n[i]=='2'){
			num[2]++;
		}
		if(n[i]=='3'){
			num[3]++;	
		}
		if(n[i]=='4'){
			num[4]++;
		}
		if(n[i]=='5'){
			num[5]++;
		}
		if(n[i]=='6'){
			num[6]++;
		}
		if(n[i]=='7'){
			num[7]++;
		}
		if(n[i]=='8'){
			num[8]++;
		}
		if(n[i]=='9'){
			num[9]++;
		}
		
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			c+=shu[i];
		}
	}
	cout<<c;
	return 0;
}
