#include<bits/stdc++.h>
using namespace std;
int arr[1000010];
int anssum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.size();
	for(int i=0;i<b;i++){
		if(a[i]>='0'&&a[i]<='9'){
			anssum++;
			arr[anssum]=((int)a[i]-48);
		}
	}
	sort(arr+1,arr+anssum+1,cmp);
	for(int i=1;i<=anssum;i++)cout<<arr[i];
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
