#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int o=0,l;
char b[1000005];
char m;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
 
for(int i=0;i<=1000006;i++){
	
	if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||
	a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
		
		b[o]=a[i];
		o++;
		 
	}
}

for(int i=0;i<o-1;i++){
	for(int j=i+1;j<o;j++){
		if(b[i]<b[j]){
			
			m=b[i];
			
			b[i]=b[j];
		
			b[j]=m;
			
			
		}
	}

}

cout <<b;







return 0;
}

