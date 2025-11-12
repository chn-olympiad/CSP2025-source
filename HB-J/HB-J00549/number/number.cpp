#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int num[1000010];
bool compete(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin >> a;
	int l = strlen(a),x=0;
	for(int i=0;i<l;i++){
		if(a[i]>='0' && a[i]<='9'){
			num[x] = a[i]-'0';
			x++;
		}
	}
	sort(num,num+x,compete);
	for(int i=0;i<x;i++) cout << num[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
