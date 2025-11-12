#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int b[N];
int cmp(int a,int b){
	return a>b;
}
int main(void){

	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);



	



	string a;
	cin>>a;
	int ans=0;
	for(int i=0; i<a.size(); i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans+=1;
		b[ans]=a[i]-'0';
		
		}
	}
	sort(b+1,b+ans+1,cmp);
	for(int i=1; i<=ans; i++){
		cout<<b[i];
	}
	return 0;
} 

