#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[10]={0,0,0,0,0,0,0,0,0,0};
	cin>>a;
	int c=a.size();
	for(int i=0;i<c;i++){
		if(a[i]=='0'){
			b[0]=b[0]+1;
		}
		else if(a[i]=='1'){
			b[1]=b[1]+1;
		}
		else if(a[i]=='2'){
			b[2]=b[2]+1;
		}
		else if(a[i]=='3'){
			b[3]=b[3]+1;
		}
		else if(a[i]=='4'){
			b[4]=b[4]+1;
		}
		else if(a[i]=='5'){
			b[5]=b[5]+1;
		}
		else if(a[i]=='6'){
			b[6]=b[6]+1;
		}
		else if(a[i]=='7'){
			b[7]=b[7]+1;
		}
		else if(a[i]=='8'){
			b[8]=b[8]+1;
		}
		else if(a[i]=='9'){
			b[9]=b[9]+1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	return 0;
	

}
