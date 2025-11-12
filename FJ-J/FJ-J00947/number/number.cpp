#include<bits/stdc++.h>
using namespace std;
string a;
int arr[15],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.length();
	for(int i=0;i<n;i++)
		if(a[i]>='0'&&a[i]<='9')
			arr[a[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(arr[i]>0){
			cout<<i;
			arr[i]--;
		}
	}
	return 0;
}
