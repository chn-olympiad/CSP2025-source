#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//
	int n,a=0;
	string s;
	cin>>s;
	n=s.length();
	int arr[n]={0};
	for(int i=0;i<n;i++){
            a++;
        if(65<=s[i]<=90 and 97<=s[i]<=122){
           countinue;
        }
        else{
            arr[i]=s[i];
        }
	}
	for(int i=0;i<n;i++){
        for(int j=n-1;j>0;j--){
           swap(arr[i],arr[i+1]);
        }
	}
	for(int i=0;i<n;i++){
        cout<<arr[i];
	}


}
