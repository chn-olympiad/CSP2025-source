#include<bits/stdc++.h>
using namespace std;
string n;
int b[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int a=n.size();
	for(int i=0;i<a;i++){
		if(n[i]=='0'){
			b[0]++;
		}else if(n[i]=='1'){
			b[1]++;
		}else if(n[i]=='2'){
			b[2]++;
		}else if(n[i]=='3'){
			b[3]++;
		}else if(n[i]=='4'){
			b[4]++;
		}else if(n[i]=='5'){
			b[5]++;
		}else if(n[i]=='6'){
			b[6]++;
		}else if(n[i]=='7'){
			b[7]++;
		}else if(n[i]=='8'){
			b[8]++;
		}else if(n[i]=='9'){
			b[9]++;
		}			
	}
	for(int i=9;i>=0;i--){
		if(b[i]!=0){
			for(int j=0;j<b[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
