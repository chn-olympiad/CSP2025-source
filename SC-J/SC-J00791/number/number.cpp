#include<bits/stdc++.h> 
using namespace std;
int main(){
	string a;
	cin>>a;
	long long s[10000];
	long long q=0;
for(int i=0;i<=a.size();i++){
	if(a[i]<='9'){
		s[q]=a[i]-48;
		q++;
		
	}
}sort(s,s+q);
for(int i=q-1;i>0;i--){
cout<<s[i];
	}
	return 0;
}