#include<iostream>
using std::cin;
using std::cout;
using std::endl;
char c[1000050];
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(int i=0;;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[c[i]-'0']++;
		}if(c[i]==0)break;
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
