#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+11;
int a[N],len;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(true){
		char tc;
		tc=getchar();
		if(tc=='\n'){
			break;
		}else if('0'<=tc&&tc<='9'){
			len++;
			a[len]=(tc-'0');
		}		
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)printf("%d",a[i]);
	return 0;
}