#include<bits/stdc++.h>
using namespace std;
int cd,t[17]; string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a; cd=a.size();
	for(int i=0;i<cd;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=t[i];j>0;j--){
			cout<<i;
		}
	} 
	return 0;
}
