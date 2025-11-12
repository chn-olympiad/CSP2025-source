#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a;
int b[1000000],ans=0;
int main(){
	//freopen("number.in",'r',stdin);
	//freopen("number.out",'w',stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[ans]=a[i]-48;
			ans++;
		}
	}
	sort(b,b+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<b[i];
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
