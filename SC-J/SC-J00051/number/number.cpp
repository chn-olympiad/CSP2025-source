#include<bits/stdc++.h>
using namespace std;
string a;   
int b[1000001],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]>='0'&&a[i]<='9')b[k++]=a[i]-'0';
		}
    sort(b,b+k);
	for(int i=k-1;i>=0;i--){
		cout<<b[i];
	}
}