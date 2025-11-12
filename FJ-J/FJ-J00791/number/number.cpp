#include<bits/stdc++.h> 
using namespace std;
int main(){
	char n[1005],c[1005];
	int m=0;
	string number;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>number;
	for(int i=0;i<number.length();i++){
		if(number[i]>='0'&&number[i]<='9'){
			n[m]=number[i];
			m++;
		}
		cout<<number;
	}
	for(int b=0;b<m;b++){
		char max=0;
		int xbmax=0;
	    for(int i=0;i<=m;i++){
		    if(n[i]>=max){
		    	max=n[i];
		    	xbmax=i;
	    	}
	    }
	    c[b]=max;
	    n[xbmax]=0;
	}
	for(int j=0;j<m;j++){
		cout<<c[j];
	}
	return 0;
}
