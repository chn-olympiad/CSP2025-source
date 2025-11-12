#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int b[1000010],k;
bool numb(char a){
	if(a<='9'&&a>='0'){
		return true;
	}
	return false;
}
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&a);
	for(int i=0;i<strlen(a);i++){
		if(numb(a[i])){
			b[k++]=a[i]-'0';
		}
	}
	sort(b,b+k,cmp);
	if(b[0]==0){
		cout<<0<<endl;
	}else{
		for(int i=0;i<k;i++){
			cout<<b[i];
		}
	}
	return 0;
} 
