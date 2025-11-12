#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b){
	if(a<b) return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	char arr[100005];
	for(int i=0;i<100005;i++){
		arr[i]=0;
	}
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' & n[i]<='9'){
			arr[i]=n[i];
			sum++;
		}
	}
	sort(arr,arr+100005,com);
	for(int i=0;i<sum;i++){
		cout<<arr[i];
	}
	return 0;
} 
