#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string n;
int a[1000010],x;
bool b(int a,int b){
	return a>b;
}int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			x++;
			a[x]=n[i]-'0';
		}
	}sort(a+1,a+x+1,b);
	for(int i=1;i<=x;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
