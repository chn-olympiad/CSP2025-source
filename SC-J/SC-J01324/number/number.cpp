#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int b[N],ind=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			int m=int(a[i]-'0');
			b[++ind]=m;
		}
	}
	sort(b+1,b+ind+1);
	for(int i=ind;i>=1;i--)cout<<b[i];
	return 0;
}
