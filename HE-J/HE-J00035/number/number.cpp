#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a<b;
};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	for(int i=0;i<=a.size();i++){
	cin >> a[i]; 
	} 
	for(int i=0;i<=a.size();i++){
		if(a[i]%2==1||a[i]%2==0){
			cout  << a[i];
		}
			break;
	}
	int sum;
	for(int i=0;i<=a.size();i++){
	if(a[i]%2==1||a[i]%2==0){
		sum=a[i];
	}
	if(sum>sum+1){
		swap(sum,sum); 	
	}
	cout << sum << endl;
}
	return 0;
} 
