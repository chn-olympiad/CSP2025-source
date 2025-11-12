#include<bits/stdc++.h>
using namespace std;
char arr[1000000];
int main(){
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	string n;
	cin>>n;
for(int i=0;i<=n.length();i++){
	if(n[i]=='0' or n[i]=='1' or n[i]=='2' or n[i]=='3' or n[i]=='4' or n[i]=='5' or n[i]=='6' or n[i]=='7' or n[i]=='8' or n[i]=='9' ){
	arr[i]=n[i];
	}
}

sort(arr,arr+n.length());
for(int i=n.length()-1;i>=0;i--){
cout<<arr[i];
}
	
	

	
	
return 0;
} 

