#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a = s.size();
    int n[a+1]={};
    if(a==1){
		cout<<s;
		return 0 ;
	}
    for(int i = 0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[i]=s[i];
		}
	}
	for(int i = 0;i<a;i++){
		if(n[i]<n[i+1]){
			swap(n[i],n[i+1]);
		}
	}
	for(int i = 0;i<a;i++){
			cout<<(char)n[i];
    }
    return 0;
}
