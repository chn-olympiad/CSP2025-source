#include<bits/stdc++.h>
using namespace std;

long long n[1000005],k=1;
string a;

int cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			n[k]=int(a[i]-'0');
			k++;
		}
	}
	sort(n+1,n+k+1,cmp);
	for(int i=1;i<k;i++){
		cout<<n[i];
	}
	
	return 0;
} 
