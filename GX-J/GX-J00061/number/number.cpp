#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    char c[100001];
    int j=0;
    int e=n.size();
    for(int i=0;i<e;i++){
		char a=n[i];
		if(a>='0'&&a<='9'){
			c[j]=a;
			j++;
	    }
    }
    sort(c,c+j);
    for(int i=j-1;i>=0;i--){
		cout<<c[i];
	}
    return 0;
}
