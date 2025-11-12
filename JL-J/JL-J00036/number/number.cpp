#include<bits/stdc++.h>
using namespace std;
int b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	int m=a.size();
	if(m==1){
		cout<<a;
		return 0;
	}
	for(int i=0;i<m;i++){
		if(a[i]=='1'){
			b[1]+=1;
		}
		else if(a[i]=='2'){
			b[2]++;
		}
		else if(a[i]=='3'){
			b[3]+=1;
		}
		else if(a[i]=='4'){
			b[4]+=1;
		}
		else if(a[i]=='5'){
			b[5]+=1;
		}
		else if(a[i]=='6'){
			b[6]+=1;
		}
		else if(a[i]=='7'){
			b[7]+=1;
		}
		else if(a[i]=='8'){
			b[8]+=1;
		}
		else if(a[i]=='9'){
			b[9]+=1;
		}
		else if(a[i]=='0'){
			b[0]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		if(b[i]!=0){
			for(int j=1;j<=b[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
	}
