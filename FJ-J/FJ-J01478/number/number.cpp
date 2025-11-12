#include<bits/stdc++.h>
using namespace std;
char a[100001];
char b[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen(" number.out","w",stdout);
	int j=0,h=0;
	cin>>a;
	for(int i=0;i<100001;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			b[j]=a[i];
			j+=1;
		}
	}
	for(int x=1;x<j;x++){
		for(int c=x;c>0;c--){
			if(b[c-1]<b[c]){
				h=b[c-1];
				b[c-1]=b[c];
				b[c]=h;
			}	
		}
		
	}
	for(int y=0;y<=j;y++){
		cout<<b[y];
	}
	return 0;
}
