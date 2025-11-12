#include<bits/stdc++.h>
using namespace std;
string a;
char b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=1;
	cin>>a;
	int c=a.size();
	for(int i=0;i<c;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i];
			k++;
		}
	}
	sort(b+1,b+k);
	for(int i=k-1;i>=1;i--) cout<<b[i];
	return 0;
}