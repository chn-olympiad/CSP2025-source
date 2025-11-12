#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001];
	int i=0;
	for(i;;i++){
		a[i]=getchar();
		if(a[i]=='\n') break;
	}
	char b[1000001];
	int cnt=0;
	for(int j=0;j<=i;j++){
		if(a[j]<='9'&&a[j]>='0'){
			b[cnt]=a[j];
			cnt++;
		} 
	}
	sort(b,b+cnt);
	for(int j=cnt;j>=0;j--){
		cout<<b[j];
	}
	return 0;
}