#include<bits/stdc++.h>
using namespace std;
int a[10008],c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x;
	cin>>x;
	for(int i=1;;i++){
		a[i]=x%10;
		x=x/10;
		c++;
		if(x<10){
			break;
		}
	}
	sort(a+1,a+c+1,cmp);
	for(int i=1;i<=c;i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
