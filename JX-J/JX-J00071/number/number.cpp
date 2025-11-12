#include <bits/stdc++.h>
using namespace std;
bool sb(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b[100],c=0,d;
    cin>>a;
    d=a.size();
    for(int i=0;i<d;i++){
		if(a[i]>='0' and a[i]<='9'){
			b[c]=a[i]-'0';
			c++;
		}
	}
	sort(b,b+c,sb);
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
    return 0;
    }
