#include<bits/stdc++.h>
using namespace std;
int a[1000000];
string c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int n=0,k=0;
	while(1){
		if(c[k]>='0' && c[k]<='9'){
			int t=c[k]-48;
			a[n]=t;
			n++;
		}
		else if(c[k]==EOF||c[k]==' '){
			break;
		}
		k++; 
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
