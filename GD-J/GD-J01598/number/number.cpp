#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char b[100000000];
int c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
			b[i]=a[i];
			c++;
		}
	}
	sort(b,b+a.size()+1,cmp);
	for(int i=0;i<c;i++){
		printf("%c",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
