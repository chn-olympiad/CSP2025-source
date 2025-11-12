#include<bits/stdc++.h>
using namespace std;
char a[100005];
int b[100005];
bool cow(int a,int b){
	if(a>b){
		return true;
	}
	return false;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=100005;i++){
		cin>>a[i];
	}
	for(int i=1;i<=100005;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-=48;
		}else{
			b[i]=-1;
		}
	}
	sort(b+1,b+100005+1,cow);
	for(int i=1;i<=100005;i++){
		if(b[i]!=-1){
			cout<<b[i];
		}
	}
	return 0;
}

