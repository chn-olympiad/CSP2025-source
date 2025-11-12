#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string ss;
int tong[15],n=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>ss;
	n=ss.size();
	for(int i=0;i<n;i++){
		if(ss[i]>='0'&&ss[i]<='9'){
			tong[(int)((int)ss[i]-(int)'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
		    cout<<i;
		}
	}
    return 0;
}
