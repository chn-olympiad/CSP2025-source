#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N]; 
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int i=0,len=n.size();
	for(int j=0;j<len;j++){
		if('0'<=n[j]&&n[j]<='9'){
			i++;
			a[i]=n[j];
		}
	}
	sort(a+1,a+i+1,cmp);
	for(int j=1;j<=i;j++){
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
