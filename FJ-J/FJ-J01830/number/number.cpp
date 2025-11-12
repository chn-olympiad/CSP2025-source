#include<bits/stdc++.h>
using namespace std;
int b[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string a;
	cin>>a;
	int q;
	for(int i=0;i<100;i++){
		if(a[i]-48>=0&&57-a[i]>=0){
			b[i]=a[i]-48;
		}
		if(a[i]==0) break;
	}
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(b[i]!=0){
				if(b[i]>b[j]){
					q=b[i];
					b[i]=b[j];
					b[j]=q;
				}
			}
		}
	}
	for(int i=0;i<100;i++){
		if(b[i]!=0) cout<<b[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
