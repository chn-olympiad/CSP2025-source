#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int a=0,ans=n.size();
	for(int i=0;i<ans;i++){
		if(n[i]>='0'&&n[i]<='9'){
			arr[a]=n[i]-'0';
			a++;
		}
	}
	a--;
	sort(arr,arr+a+1);
	for(int i=a;i>=0;i--){
		cout<<arr[i];
	}
	return 0;
}
