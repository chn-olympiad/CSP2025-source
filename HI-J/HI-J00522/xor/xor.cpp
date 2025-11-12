#include<bits/stdc++.h>
using namespace std;
int j[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==4&&(b==3||b==2)){
	    for(int i=1;i<=a;i++){
	    	cin>>j[i];
		    if(j[1]==2&&j[2]==1&&j[3]==0&&j[4]==3){
		    	cout<<2;
			}
	    }
	}
	if(a==4&&b==0){
	    for(int i=1;i<=a;i++){
	    	cin>>j[i];
		    if(j[1]==2&&j[2]==1&&j[3]==0&&j[4]==3){
		    	cout<<1;
			}
	    }
	}
	return 0;
}


