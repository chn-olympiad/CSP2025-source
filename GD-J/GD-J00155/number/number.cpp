#include<bits/stdc++.h>
using namespace std;
string a;
long long n;
long long b[1000010];
long long k=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(long long i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i]-'0';
			
			k++;
		}
	}
	sort(b,b+k,cmp);
	for(long long i=0;i<k;i++){
		cout<<b[i];
	}
	return 0;
}
