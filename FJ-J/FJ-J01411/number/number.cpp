#include <bits/stdc++.h>
using namespace std;
int b[1000001];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	int f=0;
	int u=a.length();
	for(int i=0;i<u;i++){
		b[f]=int(a[f]);
		b[f]-=48;
		if(b[f]<0&&b[f]>9){
			continue;
		}f++;
		
	} 
	for(int i=0;i<f;i++){
		for(int j=0;j<f-i;j++){
			if(b[j]<b[j+1]){
				int h=b[j];
				b[j]=b[j+1];
				b[j+1]=h; 
			}
		}
	}
	for(int i=(u-f)*2;i<f;i++){
		cout<<b[i];
	}
	return 0;
} 
