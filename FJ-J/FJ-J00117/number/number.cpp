#include<bits/stdc++.h>
using namespace std;
string a;
long long n,b;
char arr[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			arr[b]=a[i];
			b++;
		}
	
	}
	sort(arr,arr+b);
	for(int i=b-1;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}
