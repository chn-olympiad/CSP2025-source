#include<bits/stdc++.h>
using namespace std;
char a;
int b[1000000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=0;
	while(scanf("%c",&a)==1){
		if(a>='0'&&a<='9'){
			b[a-'0']++;
		}
	}
	for(int j=9;j>=1;j--){
		if(b[j]!=0){
			for(int x=1;x<=b[j];x++){
				printf("%d",j);
			}
		}
	}
	cout<<endl;
	return 0;
} 
