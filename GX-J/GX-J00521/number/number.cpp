#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
string a;
string b;
string c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0;
    cin>>a;
    for(int i=0;a[i];i++){
        if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
            b[n]=a[i];
            n++;
        }
    }
    for(int j=0;j<n-1;j++){
		for(int i=0;i<n;i++){
			if(b[i]<b[i+1]){
				c[0]=b[i];
				b[i]=b[i+1];
				b[i+1]=c[0];
			}
		}
	}
	for(int i=0;i<n;i++){
        cout<<b[i];
    }
    return 0;
}
