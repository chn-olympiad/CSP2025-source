#include<bits/stdc++.h> 
using namespace std;
char a[100005];
int b[100005];
int main(){
long long int n,e=0;
freopen("number.in","r",stdin);	
freopen("number.out","w",stdout);	
scanf("%s",&a);	
n=strlen(a);	
for(int i=0;i<=n-1;i++)	
if(a[i]>='0'&&a[i]<='9'){
	e++;
	b[e]=a[i]-'0';
}
for(int i=e-1;i>=1;i--){
	for(int j=1;j<=i;j++){
		if(b[j]<b[j+1])
		swap(b[j],b[j+1]);
	}
}	
for(int i=1;i<=e;i++){
	cout<<b[i];
}	
fclose(stdin);
fclose(stdout);
return 0;	
}
