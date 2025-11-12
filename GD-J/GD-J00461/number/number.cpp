#include<bits\stdc++.h> 
using namespace std;
string a;
int b[1000006];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int step=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9')b[step++]=a[i]-'0';
	}
	sort(b,b+step,cmp);
	for(int i=0;i<step;i++){
		cout<<b[i];
	}
	return 0;
} 
