#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,a);
    int l=a.size();
    int s=0;
    for(int i=0;i<l;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[i]=a[i]-'0';
            s++;
        }
    }
    for(int i=0;i<l;i++){
		for(int j=0;j<l-1;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}
	}
    for(int i=0;i<s;i++){
        cout<<b[i];
    }
    return 0;
}
