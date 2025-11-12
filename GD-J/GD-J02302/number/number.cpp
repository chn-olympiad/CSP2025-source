#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
char c,a[1000010];
int id;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if('0'<=c&&c<='9'){
			id+=1;
			a[id]=c;
		}
	}
	sort(a+1,a+id+1,cmp);
	if(a[1]==0){
		cout<<0;
	}
	for(int i=1;i<=id;i++){
		cout<<a[i];
	}
	return 0;
}
