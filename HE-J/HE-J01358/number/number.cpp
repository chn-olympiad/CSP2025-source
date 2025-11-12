#include<bits/stdc++.h> 
using namespace std;
int s[1000005];
int a[10],n,m;
int main(){
	freopen('number.in','r','stdin');
	freopen('number.out','w','stdout');
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++){
		if(s[i]=="0"||s[i]=="9"||s[i]>"0"&&s[i]<"9"){
			a[s[i]]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
