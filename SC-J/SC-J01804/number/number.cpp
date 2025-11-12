#include<bits/stdc++.h>
using namespace std;
bool change(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int size_a;
	string a;
	cin>>a;
	size_a=a.size();
	int max_x=-2;
	for(int i=0;i<size_a;i++){
		max_x=-2;
		for(int i=0;i<size_a;i++){
			if(a[i]>='0' && a[i]<='9'){
				if(a[i]-'0'>=a[max_x]-'0'){
					max_x=i;
				}
			}
		}
		if(max_x==-2){
			break;
		}else{
			cout<<a[max_x]-'0';
			a[max_x]='a';
		}
	}
}