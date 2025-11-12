#include<bits/stdc++.h>
using namespace std;
int b[100005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.length(),sum=0;
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-'0';
			sum++;
		}
	}
	sort(b,b+len,cmp);
	for(int i=0;i<sum;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
