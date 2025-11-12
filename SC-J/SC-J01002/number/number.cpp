#include<bits/stdc++.h>
using namespace std;
int sz[20]={0};
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0; i < a.size(); i++){
		if((int(a[i])>=int('0'))&&(int(a[i])<=int('9'))){
			sz[int(a[i])-int('0')]++;
		}
	}
	for(int i = 9;i >= 0; i--){
		if(sz[i]!=0){
			for(int j = 1; j <= sz[i]; j++){
				printf("%d",i);
			}
		} 
	}
	return 0;
}