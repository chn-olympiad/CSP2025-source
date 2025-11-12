#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),x=0;
    int arr[n];
    for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
		     arr[x]=s[i]-'0';
		     x++;
	    } 
    } 
    sort(arr,arr+x,cmp);
    for(int i=0;i<x;i++){
		cout<<arr[i];
    }
    return 0;
}
