#include<bits/stdc++.h>
using namespace std;
string a;
long long b[100005],k=0,cd;
bool cmp(int w,int n){
	return w>n;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;	
	cd=a.size();
	for(long long i=0;i<cd;i++){
		if(a[i]<65){
			b[k]=a[i]-48;
			k++;
		}
	}
	sort(b,b+k,cmp);
	for(long long i=0;i<k;i++){
		cout<<b[i];
	}
	return 0;
}
