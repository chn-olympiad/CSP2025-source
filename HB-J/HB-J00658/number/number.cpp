#include<bits/stdc++.h>
using namespace std;
char a[10000010];
int b[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0,x=0;
	cin>>a;
	int n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[k]=a[i]-48;
			k++;
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(x<=b[j]){
				x=b[j];
			}
		}
		for(int j=0;j<k;j++){
            if(b[j]==x){
                b[j]=0;
                break;
            }
		}
		cout<<x;
		x=0;
	}
	return 0;
}
