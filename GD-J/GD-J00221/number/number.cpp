#include<bits/stdc++.h>
using namespace std;
string a;
long long cnt,arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if('0'<=a[i]&&a[i]<='9'){
			arr[cnt]=(int(a[i])-48);
			cnt++;
		}
	}
	sort(arr,arr+cnt);
	for(int i=cnt-1;i>=0;i--) cout<<arr[i];
	return 0;
}
