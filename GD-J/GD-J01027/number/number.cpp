#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;	
	int b[1003]={-1};
	for(int i=0;i<1003;i++){
		b[i]=b[i]-1;
	}
	int j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48 && a[i]<=58){
			b[j]=a[i]-48;
			j++;
		}
	}
	int c=0;
	int d=0;
	for(int i=0;i<=1003;i++){
		for(int q=0;q<=i;q++){
			c=max(b[q],b[q+1]);
			d=min(b[q],b[q+1]);
			b[q]=c;
			b[q+1]=d;
		}
	}
	for(int i=0;i<j;i++){
		cout<<b[i];
	}
	return 0;
}
