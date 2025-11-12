#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b="";
	char c[1]={','};
	cin>>a;
	for(int i=0;i<a.size();i++){
        if('0'<=a[i]&&a[i]<='9'){
            b+=a[i];
        }
	}
	for(int i=0;i<b.size()-1;i++){
        for(int j=i+1;j<b.size();j++){
            if(b[i]<b[j]){
                c[0]=b[i];
                b[i]=b[j];
                b[j]=c[0];
            }
        }
	}
	cout<<b;
	return 0;
}
