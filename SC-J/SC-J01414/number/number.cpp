#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int main(){
	//记得干掉注释; 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	char a[N]={0};
	int b[N]={0};
	cin>>a;
	j=0;
	int lena=sizeof(a);
	for(i=0;i<lena;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
	if(b[j-1]==0){
		cout<<0;
		return 0;
	}
	for(i=j-1;i>=0;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 