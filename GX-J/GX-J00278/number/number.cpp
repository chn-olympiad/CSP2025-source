#include <bits/stdc++.h>
using namespace std;
int b,c;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    while(b==0){
		a[c]=b%10;
		c+=1;
		}
		sort(a,a+c);
		for(int i=0;i<c;i++){
			cout<<a[i];}
    return 0;
    }
