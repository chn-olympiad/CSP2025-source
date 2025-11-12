#include<bits/stdc++.h>
using namespace std;
char a[1000200];
int i,j=0,b[1000200];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(i=0;a[i]!='\0';i++){
		if(a[i]<='9' and a[i]>='0'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j,cmp);
	for(i=0;i<j;i++){
		cout<<b[i];
	}
	cout<<endl;
	return 0;
} 
