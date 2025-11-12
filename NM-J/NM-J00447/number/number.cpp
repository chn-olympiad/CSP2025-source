#include<bits/stdc++.h>
using namespace std;
char s[100005];
int a[100005];
bool pd(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int l=1;
   	while(cin>>s[l]){
   		l++;
	   }
	int b=1;
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i];
//			cout<<a[b]<<endl;
			b++;
		}
	}
	sort(a+1,a+b+1,pd);
	for(int i=1;i<=b;i++){
		cout<<char(a[i]);
	}
   	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
