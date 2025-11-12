#include<bits/stdc++.h>
using namespace std;
int main(){
freopen(".in","r",stdin);
freopen(".out","w",stdout);
int a,b,c=0,d,f;
int e[10000];
cin>>a>>b;
for(int i=1;i<=a*b;i++){
    cin>>e[i];
}
d=e[1];
for(int i=a*b;i>=0;i--){
	for(int j=1;j<=i;j++){
	if(e[j]<e[j+1]){
		f=e[j];
		e[j]=e[j+1];
		e[j+1]=f;
	}
	
	}
	
	}
for(int i=1;i<=a*b;i++){
   
            c++;
        if(e[c]==d){
            if(c/a%2==0&&c%b==0) cout<<c/a<<" "<<c%b;
            else if(c/a%2==1&&c%b==0) cout<<c/a<<" "<<b-c%b;
            else if(c/a%2==1) cout<<c/a+1<<" "<<b-c%b;
            else cout<<c/a+1<<" "<<c%b;
        
    }
}
fclose(stdin);
fclose(stdout);
return 0;
}
