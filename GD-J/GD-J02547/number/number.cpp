#include<bits/stdc++.h>
using namespace std;
const int SIZE=1000005;
int arr[SIZE];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<SIZE;i++) arr[i]=-1;
	string n;
	cin>>n;
	int s=0;
	for(int i=0;i<n.size();i++){
		if(char(n[i])>='0'&&char(n[i])<='9'){
			arr[s]=n[i]-'0';
			s++;
		}
	}
	int a=s;
	for(int i=0;i<s;i++){
		for(int j=0;j<a;j++)
			if(arr[j]<arr[j+1])
				swap(arr[j],arr[j+1]);
		a--;
	}
	for(int i=0;arr[i]!=-1;i++) cout<<arr[i];
	return 0;
}
